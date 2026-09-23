#include <stdio.h>

#define MAX 50

typedef enum {False,True} Bool;

typedef struct {
    char val[MAX];
    int front,rear;
} Q;

Q create() {
    Q q;
    q.front=q.rear=0;
    return q;
}

Bool isEmpty(Q q) {
    return q.front==q.rear;
}

Bool isFull(Q q) {
    return (q.rear+1)%MAX==q.front;
}

Bool insert(Q *q,char x) {
    if(isFull(*q)) return False;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=x;
    return True;
}

Bool del(Q *q,char *x) {
    if(isEmpty(*q)) return False;
    q->front=(q->front+1)%MAX;
    *x=q->val[q->front];
    return True;
}

int main() {
    Q q=create();
    char s[MAX],x;
    int i=0;

    printf("Enter the string: ");
    scanf("%49s",s);

    while(s[i]!='.' && s[i]!='\0') {
        if(!insert(&q,s[i]))
            return 0;
        i++;
    }

    if(s[i]!='.') {
        printf("It is not in w.w.w format");
        return 0;
    }

    i++;

    while(s[i]!='.' && s[i]!='\0') {
        if(isEmpty(q)) {
            printf("It is not in w.w.w format");
            return 0;
        }

        del(&q,&x);

        if(x!=s[i]) {
            printf("It is not in w.w.w format");
            return 0;
        }

        insert(&q,x);
        i++;
    }

    if(s[i]!='.') {
        printf("It is not in w.w.w format");
        return 0;
    }

    i++;

    while(s[i]!='\0') {
        if(isEmpty(q)) {
            printf("It is not in w.w.w format");
            return 0;
        }

        del(&q,&x);

        if(x!=s[i]) {
            printf("It is not in w.w.w format");
            return 0;
        }

        i++;
    }

    if(isEmpty(q))
        printf("It is in w.w.w format");
    else
        printf("It is not in w.w.w format");

    return 0;
}
