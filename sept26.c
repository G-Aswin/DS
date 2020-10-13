#include<stdio.h>

struct addr
{
    int doorno;
    char city[20];
};

typedef struct emp
{
    int eid;
    char name[20];
    float sal;
    struct addr a;
       
} E;


int main()
{
    E e1 = {112, "asw", 40000, {464, "Bng"}};
    printf("\nEid = %d\nEname = %10s\nEsal = %f\n",
    (&e1)->eid, (&e1)->name, (&e1)->sal);
}

