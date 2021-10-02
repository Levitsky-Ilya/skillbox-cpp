//
// Created by leviz on 29.09.2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#define PTR(x) std::unique_ptr<x>

#include <map>
#include <memory>
#include <set>
#include <vector>

// QUESTIONS
// Best way to store PTR(TwoDimList), and define TwoDimMatrix like this?
// "Like this" = vector of vectors, but not vector of unique_ptr to vectors
//
// How does one copy a vector of unique_ptr, if unique_ptr cannot be copied with "="?
// Any alternatives instead of using unique_ptr in this case?
using TwoDimList = std::map<int, std::set<int>>;
using TwoDimMatrix = std::vector<std::vector<bool>>;

class IGraph {
public:

    virtual ~IGraph() = default;

    IGraph() = default;

    //IGraph(IGraph *_oth) {};

    // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual void AddEdge(int from, int to) = 0;

    // Метод должен считать текущее количество вершин
    virtual int VerticesCount() const = 0;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;

};

class MatrixGraph;

class ListGraph : public IGraph {
public:

    ~ListGraph() override = default;

    ListGraph();

    explicit ListGraph(IGraph& _oth);

    ListGraph& operator=(IGraph& _oth);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void WriteMatrixToList(MatrixGraph* matrixGraph);

private:
    int m_vCount;
    PTR(TwoDimList) m_adjList;
};

class MatrixGraph : public IGraph {
public:

    ~MatrixGraph() override = default;

    MatrixGraph();

    explicit MatrixGraph(IGraph& _oth);

    MatrixGraph& operator=(IGraph& _oth);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void WriteListToMatrix(ListGraph* listGraph);

private:
    PTR(TwoDimMatrix) m_adjMatrix;
};

#endif //GRAPH_GRAPH_H
