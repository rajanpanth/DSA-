
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
        printf("Enter the data ");
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
        printf("do you want to continue? ");
        scanf("%d", &choice);
    }

    // add at the end
    choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data to put on last.. ");
        scanf("%d", &newnode->data);
        temp = head;
        while(temp->next != 0){
       temp = temp->next;
        }
        temp->next = newnode;
        temp = newnode;
        printf("do you want to add more at the end? ");
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