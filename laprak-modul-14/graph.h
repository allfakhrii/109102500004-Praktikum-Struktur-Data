#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infotype;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode
{
    infotype info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge
{
    adrNode Node;
    adrEdge Next;
};

struct Graph
{
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infotype X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

adrNode findNode(Graph G, infotype X);
void resetVisited(Graph &G);

#endif