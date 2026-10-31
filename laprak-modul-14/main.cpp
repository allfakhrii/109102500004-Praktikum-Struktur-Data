#include "graph.h"
#include <iostream>

using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(findNode(G, 'A'), findNode(G, 'B'));
    ConnectNode(findNode(G, 'A'), findNode(G, 'C'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'G'));
    ConnectNode(findNode(G, 'D'), findNode(G, 'H'));
    ConnectNode(findNode(G, 'E'), findNode(G, 'H'));
    ConnectNode(findNode(G, 'F'), findNode(G, 'H'));
    ConnectNode(findNode(G, 'G'), findNode(G, 'H'));

    cout << "--- Struktur Graph ---" << endl;
    PrintInfoGraph(G);

    cout << "\n--- Hasil Traversal DFS (Mulai dari A) ---" << endl;
    resetVisited(G);
    PrintDFS(G, findNode(G, 'A'));
    cout << endl;

    cout << "\n--- Hasil Traversal BFS (Mulai dari A) ---" << endl;
    resetVisited(G);
    PrintBFS(G, findNode(G, 'A'));
    cout << endl;

    return 0;
}