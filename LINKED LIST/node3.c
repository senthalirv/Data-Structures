#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} NODE;


NODE *create(int c, int e)
{
    NODE *n = (NODE *)malloc(sizeof(NODE));

    n->coeff = c;
    n->exp = e;
    n->next = NULL;

    return n;
}


NODE *insert(NODE *head, int c, int e)
{
    NODE *n, *temp, *prev;

    if (c == 0)
        return head;

    if (head == NULL || e > head->exp)
    {
        n = create(c, e);
        n->next = head;
        return n;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->exp > e)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == e)
    {
        temp->coeff += c;
        return head;
    }

    n = create(c, e);

    prev->next = n;
    n->next = temp;

    return head;
}


void mulsc(NODE *head, int s)
{
    while (head != NULL)
    {
        head->coeff = head->coeff * s;
        head = head->next;
    }
}


NODE *addp(NODE *p1, NODE *p2)
{
    NODE *sum = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            sum = insert(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp)
        {
            sum = insert(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            sum = insert(sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        sum = insert(sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        sum = insert(sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return sum;
}


void disp(NODE *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}


int main()
{
    NODE *p1 = NULL;
    NODE *p2 = NULL;
    NODE *sum = NULL;

    int n, c, e, s, i;


    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);

        p1 = insert(p1, c, e);
    }


    printf("\nPolynomial 1: ");
    disp(p1);


    printf("\nEnter scalar value: ");
    scanf("%d", &s);

    mulsc(p1, s);

    printf("\nAfter multiplying by %d:\n", s);
    disp(p1);


    printf("\nEnter number of terms in Polynomial 2: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);

        p2 = insert(p2, c, e);
    }


    printf("\nPolynomial 2: ");
    disp(p2);


    sum = addp(p1, p2);


    printf("\nSum of Polynomials:\n");
    disp(sum);


    return 0;
}
