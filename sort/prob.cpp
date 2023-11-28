#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head;


void Begining(int val)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = head;
    head = newnode;

    printf("Insert at Begining successfully\n");
}

void index_position()
{
    struct node*q,*p = head;
    q = p->next;

    int val,index,i = 1;
    printf("Enter the value : \n");
     scanf("%d",&val);
     printf("Enter the position : \n");
    scanf("%d",&index);

    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    while( i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = newnode;
    newnode->next = q;

}

void insertEnd()
{
    int val;
    printf("Enter the value :");
    scanf("%d",&val);

    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else{
    struct node*ptr = head;
    while(ptr ->next != NULL)
    {
        ptr = ptr->next;

    }
    ptr->next = newnode;}
}

int deletBegening()
{
     if(head == NULL)
    {
        printf("Empty\n");
    }

    else{
    struct node*p = head;
    head = head->next;
    int val = p->data;
    printf("Delet value %d\n",val);
    free(p);
    }
}

void print()
{
    struct node*p = head;
    printf("Element are : \n");
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}



int main()
{
    int choice,val;
    do{
        printf("1.Insertion at Begening\n");
        printf("2.Insertion at position\n");
        printf("3.Insertion at Ending\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Enter the value: ");
            scanf("%d", &val);
            Begining(val);
        }
        if(choice == 2)
        {
            index_position();
        }
        if(choice == 3)
        {
            insertEnd();
        }
        if(choice == 4)
        {
            print();
        }
    }while(1);
}
