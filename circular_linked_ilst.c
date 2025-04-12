#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;
}

struct node *insert_node(struct node *head, int data)
{
    struct node *temp_head = head;
    struct node *NEW_NODE = create_node(data);

    NEW_NODE->next = head;
    while (temp_head->next)
    {
        temp_head = temp_head->next;
        if (temp_head->next == head)
            break;
    }
    temp_head->next = NEW_NODE;
}
void traverse(struct node *head)
{
    struct node *temp_head = head;
    int counter = 0;
    while (temp_head)
    {
        printf("Data : %d  | Next : %p \n", temp_head->data, temp_head->next);
        temp_head = temp_head->next;

        if (temp_head == head)
        {
            printf("______________________________________________________\n");
            counter = counter + 1;
        }
        if( counter == 2)
            break;
    }
    // printf("NULL");
}
int main()
{
    struct node *head = create_node(100);

    insert_node(head, 101);
    insert_node(head, 102);
    insert_node(head, 103);
    insert_node(head, 104);
    insert_node(head, 105);
    insert_node(head, 106);
    insert_node(head, 107);
    insert_node(head, 108);
    traverse(head);
    return 0;
}