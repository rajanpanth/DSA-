
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *temp, *newnode;
    int choice = 1;
    head = 0;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("enter the data: ");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do you waht to continue? (0/1) ");
        scanf("%d", &choice);
    }

    // adding at the beggining
    choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data to add at the beggining.");
        scanf("%d", &newnode->data);

        newnode->next = head;
        head = newnode;

        printf("do you want to add more data at the beginning? (0/1)");
        scanf("%d", &choice);
    }

    // displaying
    temp = head;
    while (temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    return 0;
}
