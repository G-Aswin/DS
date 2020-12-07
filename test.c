#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * link; 
};
typedef struct node * NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Mem not allocated");
        exit(0);
    }
    // mem is allocated
    return temp;
}

NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=first;
    return temp;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp,cur,prev;
    if(first==NULL)
    {
        printf("there are no elel");
        return first; // NULL
    }
    temp=getnode();
    temp->info=item;
    temp->link=first;
    cur=first;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    return first;
}

NODE delete_front(NODE first)
{
    int elem;
    NODE next;
    if(first==NULL)
    {
        printf("no ele");
        return first;
    }
    elem=first->info;
    printf("elem deleted is %d",elem);
    next=first->link;
    free(first);
    return next;
}

NODE delete_rear(NODE first)
{
    NODE cur,prev;
    int elem;
    
    if(first==NULL)// no elem
    {
        printf("no ele");
        return first;
    }
    else if (first->link==NULL)// one Node in sll
    {
        elem=first->info;
        printf("elem deleted is %d",elem);
        free(first);
        return NULL;
    }
    else
    {
        cur=first;
        prev=NULL;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        elem=cur->info;
        printf("elem deleted is %d",elem);
        free(cur);
        prev->link=NULL;
        return first;
    }
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    if(first==NULL)// no elem
    {
        printf("no ele");
        return ;
    }
    printf("------elem of sll------\n");
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->link;
    }
}

NODE join_sll(NODE first, NODE second)
{
    NODE curr = first;
    while(curr->link != NULL)
        curr = curr->link;
    curr->link = second;
    return first;
}


int main()
{
    NODE first=NULL, second = NULL;
    int item,ch;
    while(1)
    {
        printf("1insert front  2 insert rear 3: 4 5display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the item\n");
                    scanf("%d",&item);
                    first=insert_front(first,item);
                    break;
            case 2: printf("enter the item\n");
                    scanf("%d",&item);
                    first=insert_rear(first,item);
                    break;
            case 3: first=delete_front(first);
                    break;
                    
            case 4: first=delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            default: printf("not a valid option");
                    exit(0);
                    
        }
    }
    

    return 0;
}