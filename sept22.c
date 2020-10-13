#include <stdio.h>

typedef struct emp
{
    char name[20];
    int age;
    float salary;
}E;

void accept(E *e1)
{
    scanf("%s%d%f", e1->name, &e1->age, &e1->salary);
}

void display(E *e1)
{
    printf("\nname = %s\nage = %d\nsalary = %f",
    e1->name, e1->age, e1->salary);
}



int main()
{
    E e1;
    accept(&e1);
    display(&e1);
    return 0;
}
