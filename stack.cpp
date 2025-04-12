#include <iostream>
#define stack_size 10
using namespace std;
// definition of the stack.

int stack[stack_size];
// top of the stack
int top = -1;

// Operations on the stack
// 1.Push operation pushes the value into the top of the stack.
void push(int value)
{
    if (top >= stack_size - 1)
    {
        cerr<< "Stack Overflow: Cannot push "<<endl;
        return ;
    }
    else
    {
        stack[++top] = value;
        cout << "Pushed " << value << " into the stack." << endl;
    }
}
int pop()
{
    if (top < 0)
    {
        cerr<< "Stack Underflow: Cannot pop "<<endl;
        return -1;
    }
    else
    {
        cout << "Popped " << stack[top] << " from the stack." << endl;
        return stack[top--];
    }
}
int peek()
{
    if (top < 0)
    {
        cerr<< "Stack is empty "<<endl;
        return -1;
    }
    else
    {
        cout << "Top element is " << stack[top] << endl;
        return stack[top];
    }
}
int isEmpty()
{
    if (top < 0)
    {
        cout << "Stack is empty." << endl;
        return 1;
    }
    else
    {
        cout << "Stack is not empty." << endl;
        return 0;
    }
}
int isFull()
{
    if (top = stack_size - 1)
    {
        cout << "Stack is full." << endl;
        return 1;
    }
    else
    {
        cout << "Stack is not full." << endl;
        return 0;
    }
}
void size()
{
    cout << "Size of the stack is " << top + 1 << endl;
    // return top + 1;
}
void traverse()
{
    for( int i = top-1 ; i >= 0 ; i-- )
    {
        cout << "|"<<stack[i] << "|\n";
    }
}
int main()
{
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);

    traverse();
    return 0;
}