#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *l=NULL;

NODE *create(int data)
{
    NODE *t=(NODE *)malloc(sizeof(NODE));
    t->data=data;
    t->next=NULL;
    return t;
}

NODE *insert(NODE *l, int data)
{
    NODE *t=create(data);

    if (l==NULL || data<l->data)
    {
        t->next=l;
        l=t;
        return l;
    }

    NODE *temp=l;

    while (temp->next!=NULL && temp->next->data< data)
    {
        temp=temp->next;
    }

    t->next=temp->next;
    temp->next=t;

    return l;
}

NODE *deletev(NODE *l, int value)
{
    if (l==NULL)
    {
        printf("List is empty\n");
        return l;
    }

    NODE *temp=l;
    NODE *prev=NULL;

    while (temp!=NULL && temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }

    if (temp==NULL)
    {
        printf("Element %d not found\n", value);
        return l;
    }

    if (prev==NULL)
        l=l->next;
    else
        prev->next=temp->next;

    free(temp);

    printf("Element %d deleted successfully\n", value);

    return l;
}

void asc(NODE *l)
{
    if (l==NULL)
    {
        printf("Empty List\n");
        return;
    }

    NODE *temp=l;

    printf("Ascending Order: ");

    while (temp!=NULL)
    {
        printf("%5d", temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void desc(NODE *l)
{
    if (l==NULL)
        return;

    desc(l->next);
    printf("%5d", l->data);
}


int count(NODE *l)
{
    int c=0;

    NODE *temp=l;

    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }

    return c;
}

int main()
{
    NODE *ll=NULL;

    int ch, v;

    while (1)
    {
        printf("\nSorted Linked List Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Ascending\n");
        printf("4. Display Descending\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &v);

                ll=insert(ll, v);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &v);

                ll=deletev(ll, v);
                break;

            case 3:
                asc(ll);
                break;

            case 4:
                printf("Descending Order: ");
                desc(ll);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
