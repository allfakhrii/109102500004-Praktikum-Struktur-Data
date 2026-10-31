#include "circularlist.h"

void CreateList(List &L)
{
    L.First = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P)
{
    if (L.First == Nil)
    {
        L.First = P;
        P->next = L.First;
    }
    else
    {
        address last = L.First;
        while (last->next != L.First)
        {
            last = last->next;
        }
        P->next = L.First;
        L.First = P;
        last->next = L.First;
    }
}

void insertAfter(List &L, address Prec, address P)
{
    if (Prec != Nil)
    {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P)
{
    if (L.First == Nil)
    {
        insertFirst(L, P);
    }
    else
    {
        address last = L.First;
        while (last->next != L.First)
        {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P)
{
    if (L.First != Nil)
    {
        P = L.First;
        if (P->next == L.First)
        {
            L.First = Nil;
        }
        else
        {
            address last = L.First;
            while (last->next != L.First)
            {
                last = last->next;
            }
            L.First = P->next;
            last->next = L.First;
        }
        P->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    if (Prec != Nil && Prec->next != L.First)
    {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P)
{
    if (L.First != Nil)
    {
        if (L.First->next == L.First)
        {
            deleteFirst(L, P);
        }
        else
        {
            address last = L.First;
            address prev = Nil;
            while (last->next != L.First)
            {
                prev = last;
                last = last->next;
            }
            P = last;
            prev->next = L.First;
            P->next = Nil;
        }
    }
}

address findElm(List L, infotype x)
{
    if (L.First == Nil)
    {
        return Nil;
    }
    address P = L.First;
    do
    {
        if (P->info.Nim == x.Nim)
        {
            return P;
        }
        P = P->next;
    } while (P != L.First);

    return Nil;
}

void printInfo(List L)
{
    if (L.First != Nil)
    {
        address P = L.First;
        do
        {
            cout << "Nama : " << P->info.Nama << endl;
            cout << "NIM  : " << P->info.Nim << endl;
            cout << "L/P  : " << P->info.Jenis_kelamin << endl;
            cout << "IPK  : " << P->info.Ipk << endl;
            cout << endl;
            P = P->next;
        } while (P != L.First);
    }
}