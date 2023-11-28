#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head;

int isEmpty()
{
    return(head == NULL)?1:0;
}

int delet1st()
{
    if(isEmpty())
    {
        printf("List is Empty\n");
    }
    else{
    struct node*p = head;
    head = head->next;
    int val = p->data;
    free(p);
    printf("deleted element %d\n",val);
    }

}

int delet_last()
{
    if(isEmpty())
    {
        printf("List is Empty\n");
    }
    else{
        struct node*q,*p = head;
        q = p->next;
        while( q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        int val = q->data;
        p->next = NULL;
        free(q);
        printf("Delet Element %d\n",val);
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

int delet_position(int index)
{
    int i = 1;
    if(isEmpty())
    {
       printf("List is Empty\n");

    }
    else
    {
        struct node*q,*p = head;
       q = head->next;

        while( i != index-1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        int val = q->data;
        free(q);
        printf("Delet Element %d\n",val);
    }
}



int main()
{
    struct node*node1,*node2,*node3,*node4,*node5;

    node1 = (struct node*)malloc(sizeof(struct node));
    node2 = (struct node*)malloc(sizeof(struct node));
    node3 = (struct node*)malloc(sizeof(struct node));
    node4 = (struct node*)malloc(sizeof(struct node));
    node5 = (struct node*)malloc(sizeof(struct node));

    node1->data = 55;
    node1->next = node2;

    node2->data = 66;
    node2->next = node3;

     node3->data = 77;
    node3->next = node4;

    node4->data = 88;
    node4->next = node5;

    node5->data = 99;
    node5->next = NULL;

    head = node1;
    print();

    /*delet1st();
    print();

    delet_last();
     print();*/


    delet_position(3);
    print();
}
