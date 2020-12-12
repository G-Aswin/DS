#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * link;
};
typedef struct node * NODE;
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("memory not available");
    }
    return x;
}

NODE insert_front(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
        last=temp;
    else
        temp->link=last->link;
    last->link=temp;
    return last;
}

NODE insert_rear(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    last=temp;
    return last;
}

NODE delete_front(NODE last)
{
    NODE front;
    if(last=NULL){
        printf("list is empty");
        return NULL;
    }
    else if(last->link=last)
    {
        printf("the deleted element is %d",last->info);
        free(last);
        return NULL;
    }
    front=last->link;
    last->link=front->link;
    printf("the deleted element is %d",front->info);
    free(front);
    return last;
}

NODE delete_rear(NODE last){
    if(last==NULL)
    {
        printf("there are no elements in CLL\n");
        return NULL;
    }
    else if(last->link==last)
    {
        printf("element deleted is %d",last->info);
        free(last);
        return NULL;
    }
    NODE prev;
    prev=last->link;
    while(prev->link!=last)
        prev=prev->link;
    printf("element deleted is %d",last->info);
    prev->link=last->link;
    free(last);
    return prev;
}

void display(NODE last)
{
    if(last==NULL){
        printf("there are no elements in linked list\n");
        return;
    }
    NODE cur;
    cur=last->link;
    printf("elements of CLL are:\n");
    while(cur!=last)
    {
        printf("%d",cur->info);
        cur=cur->link;
    }
    printf("%d\n",last->info);
}
int main()
{
    NODE last;
    int op,elem;
    while(1)
    {
        printf("enter 1.insert_front\n2.insert_rear\n3.delete_front\n4.delete_rear\n5.display\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("enter the element\n");
                    scanf("%d",&op);
                    last=insert_front(last,elem);
                    break;
            case 2:printf("enter the element\n");
                    scanf("%d",&elem);
                    last=insert_rear(last,elem);
                    break;
            case 3:last=delete_front(last);
                    break;
            case 4:last=delete_rear(last);
                    break;
            case 5:display(last);
        }
        
    }

    return 0;
}