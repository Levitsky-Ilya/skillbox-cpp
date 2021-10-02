#include <iostream>

#include "graph.h"

int main() {
    ListGraph a;
    MatrixGraph b;
    a.AddEdge(0,1);
    a.AddEdge(1,2);
    a.AddEdge(2,4);
    a.AddEdge(3,2);
    a.AddEdge(3,4);
    a.AddEdge(4,3);
    a.AddEdge(5,4);
    a.AddEdge(2,5);
    a.AddEdge(5,6);
    std::cout << "N(a) = " << a.VerticesCount() << "\n";

    b.AddEdge(1,0);
    b.AddEdge(2,1);
    b.AddEdge(4,2);
    b.AddEdge(2,3);
    b.AddEdge(4,3);
    b.AddEdge(3,4);
    b.AddEdge(4,5);
    b.AddEdge(5,2);
    b.AddEdge(6,5);
    std::cout << "N(b) = " << b.VerticesCount() << "\n";

    ListGraph c(b);
    MatrixGraph d(a);
    a = d;

    std::vector<int> vertices;

    a.GetNextVertices(2, vertices);
    a.GetPrevVertices(2, vertices);
    b.GetNextVertices(2, vertices);
    b.GetPrevVertices(2, vertices);
    c.GetNextVertices(2, vertices);
    c.GetPrevVertices(2, vertices);
    d.GetNextVertices(2, vertices);
    d.GetPrevVertices(2, vertices);
    return 0;
}

