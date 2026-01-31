
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

//count the nodes
int count = 0;
temp = head;
while(temp != 0){
    count++;
    temp = temp->next;
}

//for displaying
temp = head;
printf("\nThe datas are: ");
while(temp != 0){
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("\nTotal number of nodes: %d\n", count);
return 0;
}

