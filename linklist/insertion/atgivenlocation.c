#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;
    int choice = 1;
    head = 0;
    int pos;
    int i = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node)); // Allocate FIRST
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
        printf("do you want to continue: (1/0): ");
        scanf("%d", &choice);
    }

    // insert after the given position
    printf("enter the position: ");
    scanf("%d", &pos);

    // count nodes
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }

    if (pos > count)
    {
        printf("invalid location");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        printf("enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;

        // display data
        temp = head;
        printf("the datas are: \n");
        while (temp != 0)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
}