#include <stdio.h>
#include <stdlib.h>
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
	if(temp == NULL)
	{
		printf("NO memory allocated\n");
		exit(0);
	}
	return temp;
}
void insert_front(NODE head,int item)
{
	NODE temp,next;
	temp=getnode();
	next=head->link;
	temp->info=item;
	head->link=temp;
	temp->link=next;
}
void insert_rear(NODE head,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	cur=head;
	while(cur->link!=NULL)
	{
	    cur=cur->link;
	}
	cur->link=temp;
}
void delete_front(NODE head)
{
    NODE first,next;
    if(head->link==NULL)
    {
            printf("Header is empty");
    }
    else
    {
        first=head->link;
        next=first->link;
        printf("Deleted elem = %d",first->info);
        free(first);
        head->link=next;
    }
}
void delete_rear(NODE head)
{
    NODE cur,prev;
    if(head->link==NULL)
    {
            printf("Header is empty");
    }
    else
    {
        cur=head;
        prev=NULL;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("Deleted elem = %d",cur->info);
        free(cur);
        prev->link=NULL;
    }
}
void display(NODE head)
{
	NODE cur;
	cur=head->link;
	if(cur== NULL)
	{
		printf("empty header\n");
		return;
	}
	else
	{
    	while(cur!=NULL)
    	{
    		printf("%d\n",cur->info);
    		cur=cur->link;
    	}
	}
	// printf("%d",cur->info);
}
int main()
{
	NODE head = getnode();
	head->link = NULL;
	int item,ch,n;
	printf("Enter no nodes you want to create\n");
    scanf("%d",&n);
	while(1)
	{
		printf("MENU\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n Enter Choice:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the item\n");
                    scanf("%d",&item);
			        insert_front(head,item);
			        break;
			case 2: printf("Enter the item\n");
                    scanf("%d",&item);
			        insert_rear(head,item);
			       break;
			case 3:printf("Enter the item to be deleted from front\n");
                   scanf("%d",&item);
			       delete_front(head);
			       break;
			case 4:printf("Enter the item to be deleted from rear\n");
                   scanf("%d",&item);
			       delete_rear(head);
			       break;
		    case 5:display(head);
			       break;
			default:return (0);
		}
	}
}