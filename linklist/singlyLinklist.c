#include <stdio.h>

// creating a node
struct node
{
    int data;
    struct node *next; // points to the next node via self-referential structures
};

// Let us see how a three-member (45, 98, 3) singly linked list can be created:
int main()
{
    struct node *head = (int *)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node *current = (int*)malloc(sizeof(struct node));
    current->data = 28;
    current->next = NULL;
    head->next = current;

   struct node *current1 = (int*)malloc(sizeof(struct node));
    current1->data = 44;
    current1->next = NULL;
    current->next = current1;
    return 0;
}