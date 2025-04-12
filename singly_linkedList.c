#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// Creation of the node 
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;
};

// Insertion of the nodes and its types .

// timecomplexity = O(1)
struct node *front_insertion(struct node *head, int data)
{
    struct node *node = create_node(data);

    node->next = head;

    return node;
}
// timecomplexity = O(n)
struct node *back_insertion(struct node *head, int data)
{
    struct node *node = create_node(data);
    struct node *temp_head = create_node(data);

    temp_head = head;
    while (temp_head->next)
    {
        temp_head = temp_head->next;
    }
    temp_head->next = node;
}
// timecomplexity o(nlog n)
void insert_at_middle(struct node *head, int data)
{
    struct node *new_node = create_node(data);
    struct node *temp_head = head;
    int len_counter = 0;

    while (temp_head->next)
    {
        temp_head = temp_head->next;
        len_counter++;
    }
    temp_head = head;

    if (len_counter % 2)
    {
        int middle = (len_counter / 2) + 1;
        for (int i = 0; i < middle; i++)
        {
            temp_head = temp_head->next;
        }
        new_node->next = temp_head->next;
        temp_head->next = new_node;
    }
    else
    {
        int middle = (len_counter / 2);
        for (int i = 0; i < middle; i++)
        {
            temp_head = temp_head->next;
        }
        new_node->next = temp_head->next;
        temp_head->next = new_node;
    }
}
void traverse(struct node *head)
{
    struct node *temp_head = head;
    printf("\nData in the Linked list are  :\n");
    while (temp_head)
    {
        printf("%d -> ", temp_head->data);
        temp_head = temp_head->next;
    }
    printf("NULL");
}
// Deletion operation.
void front_deletion(struct node *head)
{
    if(!head->next)
    {
        printf("cannot delete the linked list.\n");
    }
    head = head->next;
}
// main control of the datastructures.
int main()
{
    struct node *head = create_node(100);

    head = front_insertion(head, 101);
    head = front_insertion(head, 102);
    head = front_insertion(head, 103);
    head = front_insertion(head, 104);
    head = front_insertion(head, 105);

    traverse(head);
    return 0;
}
