#include <stdio.h>
#define cap 3   //Capacity of the queue .
// definition of the queue with the size capacity.
int queue[cap];

// Variable to trace the size and the index pointers front and the rear.
int size = 0;
int front = 0;
int rear = -1;

// The enqueue Functionf for the insertion of the data at the end of the queue.
void enqueue(int data)
{
    // Checks if the difference between the current size of the Queue and the capacity is equal any more addition may cause in overflow.
    if(cap - size == 0)
    {

        printf("The Queue Is Full.\n");
        printf("Couldnot Enqueue %d \n" , data);    
        return;
    }
    // if Not Full then we increase the index for where the value needs to go that is the rear end. hence (rear++)
    rear++;

    // Note that the indexing of the queue here is quite weird . this is to demonstrate the proper need of the circular queue.

    // This operation helps in recovering the lost memory (lost index).

    // What it does : 
        // for the queue [ 1 , 2 , 3]
        // if deueud [no_data , 2 , 3]
        // if it were a linear queue this would be the end thats it . but since this is a cricluar queue we must go on a loop that is now to take the remaining space.
        // After after tracing the rear index we can check if it exceeds the capacity and if it does it simply means the array index is full but we still got some space in the beginning.
        // Then we can use the modulo operation to reset the rear end back into 0 and continue as if nothing happened.
    queue[rear % cap] = data;
    size++;
    if(rear >=cap)
    {
        front = 0;
    }
}
void dequeue()
{
    // If the size is 0 and ! of 0  means True and if there is no size means its empty. 
    if (!size)
    {
        printf("\nThe Queue Is empty \nTry enqueing a data before dequeing it.");
        return ;
    }
    // if not empty.
    printf("dequeue Sucessful!\n");
    front++;
    size--;
}
void traverse()
{
    // its just traversal from front to back.

    for (int i = front; i < cap; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    // enqueue(4);
    dequeue();
    enqueue(99);
    dequeue();
    enqueue(98);
    dequeue();
    enqueue(97);
    dequeue();
    enqueue(96);
    // dequeue();
    // dequeue();
    // dequeue();
    


    traverse();
    return 0;
}