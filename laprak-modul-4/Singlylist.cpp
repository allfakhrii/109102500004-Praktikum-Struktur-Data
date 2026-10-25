#include "Singlylist.h"

void CreateList(List &L)
{
    first(L) = nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    if (P != nil)
    {
        info(P) = x;
        next(P) = nil;
    }
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = nil;
}

void printInfo(List L)
{
    address P = first(L);
    if (P == nil)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        while (P != nil)
        {
            cout << info(P) << " ";
            P = next(P);
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P)
{
    if (first(L) == nil)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}