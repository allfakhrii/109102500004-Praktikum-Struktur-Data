#include "bstree.h"

address alokasi(infotype x)
{
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x)
{
    if (root == Nil)
    {
        root = alokasi(x);
    }
    else if (x < root->info)
    {
        insertNode(root->left, x);
    }
    else if (x > root->info)
    {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root)
{
    if (root == Nil || root->info == x)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(x, root->left);
    }
    else
    {
        return findNode(x, root->right);
    }
}

void InOrder(address root)
{
    if (root != Nil)
    {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

void printInorder(address root)
{
    InOrder(root);
}

int hitungNode(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start)
{
    if (root == Nil)
    {
        return start;
    }
    int kedalamanKiri = hitungKedalaman(root->left, start + 1);
    int kedalamanKanan = hitungKedalaman(root->right, start + 1);

    return (kedalamanKiri > kedalamanKanan) ? kedalamanKiri : kedalamanKanan;
}

void printPreOrder(address root)
{
    if (root != Nil)
    {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root)
{
    if (root != Nil)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}