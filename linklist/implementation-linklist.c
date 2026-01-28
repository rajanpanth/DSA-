#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head, *newnode, *temp;
    int choice = 1;

    head = 0;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0,1)? ");
        scanf("%d", &choice);
    }

    // Display the linked list
    temp = head;
    printf("\nLinked list elements are:\n");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    getch();
}
