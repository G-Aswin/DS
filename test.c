#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  node 
{
    char nm[50];
    char usn[50];
    int marks;
    struct node * link;
};
typedef struct node nd;

nd *  insert_front( nd * );
void  display( nd * );
nd * insert_end( nd *);
nd * insert_post( nd * );
nd * delete_front(nd * );
nd *delete_rear(nd *);


int main()
{
     nd * first = NULL;   int ch;
    for(; ;)   {
    printf("1. Insert front\n2.Display\n3.Insert end\n4.Insert Position\n5.Delete Front\n");
    printf("6. Delete Rear\n7.exit\n");
    printf("Enter choice: "); scanf("%d",&ch);
    switch(ch)   {
        case 1: first = insert_front(first); break;
        case 2: display(first); break;
        case 3: first = insert_end(first); break;
        case 4: first = insert_post(first); break;
        case 5: first = delete_front(first);break;
        case 6: first = delete_rear(first); break;
        case 7: return 0;
    }
   }
}

nd * insert_front( nd * f)  {
    nd* t;
    t = (nd *) malloc(sizeof(nd));
    printf("enter the student info\n");
   scanf("%s %s %d",t->nm,t->usn,&(t->marks));
   t->link=0;

   if    (f  != NULL)
        t->link = f;
 return t;      }

void display( nd * f)  {
  if   ( f  ==  NULL)    {
    printf("LL is empty\n");
   return;
}
for( ;  f != NULL; )   {
    printf("%s %s %d\n", f->nm,f->usn,(f->marks));
    f = f -> link;
}
}

nd *    insert_end (  nd * f)
{
    nd * last;       nd * t = (nd *) malloc(sizeof(nd));
        scanf("%s%s%d",t->nm,t->usn, &(t->marks));  t->link = NULL;

    if (  f == NULL)
      return t;

       for( last = f;  last->link != NULL; last = last->link);

      last->link = t;
     return f;     //not at all modified
}
nd *  insert_post(nd * f)
{
   int  cnt=0, pos;
   nd *t, *p, *n ;
   printf("Enter position value\n");  scanf("%d", &pos);

   t = (nd *) malloc(sizeof(nd));  
   scanf("%s%s%d",t->nm,t->usn,&(t->marks));
   t->link = NULL;


//LL is empty AND pos = 1
if ( f  == NULL  && pos == 1)
     return t;

 //  LL is not empty AND pos = 1
  if ( f != NULL && pos == 1)
   {
       t->link = f;
      return t;
   }

    // to count no of nodes in LL
   for(p=f;  p != 0; p = p->link, cnt++);

   if( f!=NULL && pos > cnt+1){
        printf("Overflow!!!You cannot insert leaving a node empty!\n");
        return f;
    }
   // LL is not empty AND pos = cnt+1
   if (  f != NULL && pos == cnt+1)
   {
     for(p=f; p->link != 0; p=p->link);

     p->link = t;
    return f;
  }

   for( p=0, n=f;  pos>0; pos--, p=n, n=n->link);

    p->link = t;
    t->link = n;
   return f;
}
nd *   delete_front ( nd * f )
{
    nd * t;
   if(f == NULL)
   {
    printf("LL is empty\n");
    return   f;
   }

   printf("Student deleted is %s\n",f->usn);
  if(f->link == NULL)
  {
    free( f );
   return 0;
  }
  t=f;      
  f=f->link;
  free(t);
  return f;     
}

nd *delete_rear (nd* f)
{
    nd *c = f;
    if (f == NULL)
    {
        printf("LL is empty\n");
        return f;
    }
    if (c->link == NULL)
    {
        f = NULL;
        free(c);
        return f;
    }
    while (c->link->link != NULL)
        c = c->link;
    nd *temp = c->link;
    c->link = NULL;
    free(temp);   
    return f;
}

