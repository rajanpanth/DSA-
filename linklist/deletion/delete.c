#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp, *newnode;
int choice;

void createLinkList()
{
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
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

        printf("Do you want to continue (0,1):");
        scanf("%d", &choice);
    }
}

void deleteFromBeg()
{
    struct node *temp;

    if (head == 0)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd()
{
    struct node *temp, *prevnode;

    if (head == 0)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    // only one node
    if (temp->next == 0)
    {
        head = 0;
        free(temp);
        return;
    }
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = 0;
    free(temp);
}

void DeleteFromPos()
{
    struct node *nextnode;
    int pos, i = 1;

    temp = head;

    printf("Enter Position: ");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

void display()
{
    temp = head;
    printf("\nThe datas are: ");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = 0;
    choice = 1;
    createLinkList();
    deleteFromBeg();
    deleteFromEnd();
    DeleteFromPos();
    display();
    
    return 0;
}
