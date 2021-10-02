//
// Created by leviz on 01.10.2021.
//

#include "graph.h"

///***** ListGraph *****///

ListGraph::ListGraph() :
    m_vCount(0),
    m_adjList(new TwoDimList) {}

ListGraph::ListGraph(IGraph& _oth) : ListGraph() {
    if (auto* listGraph = dynamic_cast<ListGraph*>(&_oth)) {
        m_adjList = std::make_unique<TwoDimList>(*listGraph->m_adjList);
    } else if (auto* matrixGraph = dynamic_cast<MatrixGraph*>(&_oth)) {
        WriteMatrixToList(matrixGraph);
    } else {
        return;
    }
}

ListGraph &ListGraph::operator=(IGraph& _oth) {
    if (this == &_oth) {
        return *this;
    }

    // This portion of code is duplicated. Move to a new function?
    if (auto* listGraph = dynamic_cast<ListGraph*>(&_oth)) {
        m_adjList = std::make_unique<TwoDimList>(*listGraph->m_adjList);
        m_vCount = listGraph->m_vCount;
    } else if (auto* matrixGraph = dynamic_cast<MatrixGraph*>(&_oth)) {
        WriteMatrixToList(matrixGraph);
    }

    return *this;
}

void ListGraph::AddEdge(int from, int to) {
    if (from < 0 || to < 0) {
        return;
    }

    // The maximum order number of a vertex defines cardinality of the graph.
    if (from >= m_vCount || to >= m_vCount) {
        m_vCount = ((from > to) ? from : to) + 1;
    }

    //m_adjList->emplace({from});
    (*m_adjList)[from].emplace(to);
}

int ListGraph::VerticesCount() const {
    return m_vCount;
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    int vCount = VerticesCount();
    if (vertex < 0 || vertex >= vCount) {
        return;
    }

    vertices.clear();

    if (m_adjList->find(vertex) != m_adjList->end()) {
        for (const auto& vTo : m_adjList->at(vertex)) {
            vertices.push_back(vTo);
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const  {
    int vCount = VerticesCount();
    if (vertex < 0 || vertex >= vCount) {
        return;
    }

    vertices.clear();
    for (const auto& vFromList : *m_adjList) {
        if (vFromList.second.find(vertex) != vFromList.second.end()) {
            vertices.push_back(vFromList.first);
        }
    }
}

void ListGraph::WriteMatrixToList(MatrixGraph* matrixGraph) {
    if (matrixGraph == nullptr) {
        return;
    }

    m_adjList->clear();

    m_vCount = matrixGraph->VerticesCount();

    for (int vFromIndex = 0; vFromIndex < m_vCount; vFromIndex++) {
        std::vector<int> nextVertices;
        matrixGraph->GetNextVertices(vFromIndex, nextVertices);

        if (!nextVertices.empty()) {
            for (const auto& vToIndex : nextVertices) {
                (*m_adjList)[vFromIndex].emplace(vToIndex);
            }
        }
    }
}

///***** MatrixGraph *****///

MatrixGraph::MatrixGraph() :
    m_adjMatrix(new TwoDimMatrix) {}
    
MatrixGraph::MatrixGraph(IGraph& _oth) : MatrixGraph() {
    if (auto* listGraph = dynamic_cast<ListGraph*>(&_oth)) {
        WriteListToMatrix(listGraph);
    } else if (auto* matrixGraph = dynamic_cast<MatrixGraph*>(&_oth)) {
        *m_adjMatrix = *matrixGraph->m_adjMatrix;
    } else {
        return;
    }
}

MatrixGraph &MatrixGraph::operator=(IGraph& _oth) {
    if (this == &_oth) {
        return *this;
    }

    // This portion of code is duplicated. Move to a new function?
    if (auto* listGraph = dynamic_cast<ListGraph*>(&_oth)) {
        WriteListToMatrix(listGraph);
    } else if (auto* matrixGraph = dynamic_cast<MatrixGraph*>(&_oth)) {
        // Reference may be null (here even after if)?
        *m_adjMatrix = *matrixGraph->m_adjMatrix;
    }

    return *this;
}

void MatrixGraph::AddEdge(int from, int to)  {
    if (from < 0 || to < 0) {
        return;
    }

    // The maximum order number of a vertex defines cardinality of the graph.
    int vCount = VerticesCount();
    if (from >= vCount || to >= vCount) {
        int newVCount = ((from > to) ? from : to) + 1;
        m_adjMatrix->resize(newVCount);
        for (auto& row : *m_adjMatrix) {
            row.resize(newVCount);
        }
    }

    (*m_adjMatrix)[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return m_adjMatrix->size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const  {
    int vCount = VerticesCount();
    if (vertex < 0 || vertex >= vCount) {
        return;
    }

    vertices.clear();

    const auto& vFromRow = m_adjMatrix->at(vertex);
    for (int vToIndex = 0; vToIndex < vCount; vToIndex++) {
        if (vFromRow[vToIndex]) {
            vertices.push_back(vToIndex);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    int vCount = VerticesCount();
    if (vertex < 0 || vertex >= vCount) {
        return;
    }

    vertices.clear();

    for (int vFromIndex = 0; vFromIndex < vCount; vFromIndex++) {
        const auto& vFromRow = m_adjMatrix->at(vFromIndex);
        if (vFromRow[vertex]) {
            vertices.push_back(vFromIndex);
        }
    }
}

void MatrixGraph::WriteListToMatrix(ListGraph *listGraph) {
    if (listGraph == nullptr) {
        return;
    }

    m_adjMatrix->clear();

    int vCount = listGraph->VerticesCount();
    m_adjMatrix->resize(vCount);
    for (auto& vFromRow : *m_adjMatrix) {
        vFromRow.resize(vCount);
    }

    for (int vFromIndex = 0; vFromIndex < vCount; vFromIndex++) {
        std::vector<int> nextVertices;
        listGraph->GetNextVertices(vFromIndex, nextVertices);

        if (!nextVertices.empty()) {
            for (const auto& vToIndex : nextVertices) {
                (*m_adjMatrix)[vFromIndex][vToIndex] = true;
            }
        }
    }
}
