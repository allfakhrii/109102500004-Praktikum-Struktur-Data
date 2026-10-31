#include "graph.h"

void CreateGraph(Graph &G)
{
    G.first = NULL;
}

void InsertNode(Graph &G, infotype X)
{
    adrNode p = new ElmNode;
    p->info = X;
    p->visited = 0;
    p->firstEdge = NULL;
    p->Next = NULL;

    if (G.first == NULL)
    {
        G.first = p;
    }
    else
    {
        adrNode q = G.first;
        while (q->Next != NULL)
        {
            q = q->Next;
        }
        q->Next = p;
    }
}

void ConnectNode(adrNode N1, adrNode N2)
{
    if (N1 != NULL && N2 != NULL)
    {
        adrEdge e1 = new ElmEdge;
        e1->Node = N2;
        e1->Next = N1->firstEdge;
        N1->firstEdge = e1;

        adrEdge e2 = new ElmEdge;
        e2->Node = N1;
        e2->Next = N2->firstEdge;
        N2->firstEdge = e2;
    }
}

void PrintInfoGraph(Graph G)
{
    adrNode p = G.first;
    while (p != NULL)
    {
        cout << "Node " << p->info << " terhubung dengan: ";
        adrEdge e = p->firstEdge;
        while (e != NULL)
        {
            cout << e->Node->info << " ";
            e = e->Next;
        }
        cout << endl;
        p = p->Next;
    }
}

void PrintDFS(Graph G, adrNode N)
{
    if (N != NULL)
    {
        N->visited = 1;
        cout << N->info << " ";

        adrEdge e = N->firstEdge;
        while (e != NULL)
        {
            if (e->Node->visited == 0)
            {
                PrintDFS(G, e->Node);
            }
            e = e->Next;
        }
    }
}

void PrintBFS(Graph G, adrNode N)
{
    if (N != NULL)
    {
        adrNode queue[100];
        int head = 0, tail = 0;

        queue[tail++] = N;
        N->visited = 1;

        while (head < tail)
        {
            adrNode curr = queue[head++];
            cout << curr->info << " ";

            adrEdge e = curr->firstEdge;
            while (e != NULL)
            {
                if (e->Node->visited == 0)
                {
                    e->Node->visited = 1;
                    queue[tail++] = e->Node;
                }
                e = e->Next;
            }
        }
    }
}

adrNode findNode(Graph G, infotype X)
{
    adrNode p = G.first;
    while (p != NULL)
    {
        if (p->info == X)
            return p;
        p = p->Next;
    }
    return NULL;
}

void resetVisited(Graph &G)
{
    adrNode p = G.first;
    while (p != NULL)
    {
        p->visited = 0;
        p = p->Next;
    }
}