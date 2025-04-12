#include <stdio.h>
#define queue_size 100
// Fnction declaration:
void dequeue();
void enqueue(int data);
int isfull();
int isempty();


int queue[queue_size];
int front = 0;
int rear = 0;

void dequeue()
{
    if (front >= rear)
    {
        printf("Operation Invalid !!\nEmpty Queue!!.\n");
    }
    front++;
}
void enqueue(int data)
{
    if(isfull())
    {
        printf("Invalid !!\nQueue Full\n");
        return ;
    }
    queue[rear] = data;
    rear++;
}
void traversal()
{
    printf("data in the Queue : \n");
    for (int i = front; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int isfull()
{
    return(rear == queue_size - 1);
}
int isempty()
{
    return (front == rear);
}
int main()
{
    for (int i = 0 ; i <queue_size-1; i ++)
        enqueue(100);
    // enqueue(101);
    // enqueue(102);

    // dequeue();
    // dequeue();
    // dequeue();
    // traversal();
    printf("Output to the Isfull() function : %d \n" , isfull());
    printf("Output to the Isempty() function : %d \n" , isempty());

    return 0;
}
