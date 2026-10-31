#include "stack.h"

void createStack(Stack &S)
{
    S.top = -1;
}

bool isEmpty(Stack S)
{
    return S.top == -1;
}

bool isFull(Stack S)
{
    return S.top == 19;
}

void push(Stack &S, infotype x)
{
    if (!isFull(S))
    {
        S.top++;
        S.info[S.top] = x;
    }
    else
    {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S)
{
    infotype x = -999;
    if (!isEmpty(S))
    {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S)
{
    if (isEmpty(S))
    {
        cout << "[TOP] Stack kosong" << endl;
    }
    else
    {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--)
        {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S)
{
    if (!isEmpty(S))
    {
        int temp[20];
        int count = 0;

        while (!isEmpty(S))
        {
            temp[count] = pop(S);
            count++;
        }

        for (int i = 0; i < count; i++)
        {
            push(S, temp[i]);
        }
    }
}

void pushAscending(Stack &S, infotype x)
{
    Stack tempStack;
    createStack(tempStack);

    while (!isEmpty(S) && S.info[S.top] > x)
    {
        push(tempStack, pop(S));
    }

    push(S, x);

    while (!isEmpty(tempStack))
    {
        push(S, pop(tempStack));
    }
}

void getInputStream(Stack &S)
{
    char ch;
    while (cin.get(ch))
    {
        if (ch == '\n')
        {
            break;
        }
        if (ch >= '0' && ch <= '9')
        {
            int val = ch - '0';
            push(S, val);
        }
    }
}