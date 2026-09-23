#include <stdio.h>
#define MAX 50
typedef enum{False,True}Bool;
typedef struct{
    char val[MAX];
    int front;
    int rear;
}Q;
Q create(){
    Q q;
    q.front=0;
    q.rear=0;
    return q;
}


Bool isEmpty(Q q){
    return (q.front==q.rear);
}
Bool isFull(Q q){
    return ((q.rear+1)%MAX==q.front);
}

Bool insert(Q *q, char x)
{
    if(isFull(*q)) return False;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=x;
    return True;
}



Bool del(Q *q,char *val){
    if(isEmpty(*q)) return False;
    q->front=(q->front+1)%MAX;
    *val=q->val[q->front];
    return True;
}
void print(Q q){
    if(isEmpty(q)) return;
    int i = (q.front + 1) % MAX;
    while(i != (q.rear + 1) % MAX) {
        printf("%c\t", q.val[i]);
            i = (i + 1) % MAX;
    }
}

int main(){
    Q q;
    q=create();
    char str[50];
    printf("Enter the string:");
    scanf("%s",str);
    char ch;int i=0;

    while(str[i] != '.'){
        insert(&q,str[i]);
        i++;
    }
    i++;

    while(str[i] != '.' && str[i] != '\0')
    {
        if(isEmpty(q)) return 0;
        del(&q,&ch);
        if(ch!=str[i]){
            printf("It is not in w.w.w format");
            return 0;
        }
        insert(&q,ch);
        i++;
    }
    if(str[i]=='.')
        i++;
    while(str[i]!='\0')
    {
        if(isEmpty(q))return 0;
        del(&q,&ch);
        if(ch!=str[i])
        {
            printf("It is not in w.w.w format");
            return 0;
        }
        i++;
    }
    if(isEmpty(q))
        printf("It is in w.w.w format");
    else
        printf("It is not in w.w.w format");
}
