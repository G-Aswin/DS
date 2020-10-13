#include <stdio.h>

typedef struct emp
{
  char name[20];
  int age;
  float salary;
}E;

void swap_struct(E *e1, E *e2)
{
  E temp;
  temp = *e1;
  *e1 = *e2;
  *e2 = temp;
}

void accept(E *e1)
{
    scanf("%s%d%f", e1->name, &e1->age, &e1->salary);
}

void display(E *e1)
{
    printf("\nname = %s\nage = %d\nsalary = %f\n",
    e1->name, e1->age, e1->salary);
}

int main()
{
  E e1, e2;
  printf("Accepting E1: \n");
  accept(&e1);
  printf("Accepting E2: \n");
  accept(&e2);
  printf("Showing E1\n");
  display(&e1);
  printf("Showing E2\n");
  display(&e2);

  printf("Swapping them\n");
  swap_struct(&e1, &e2);

  printf("Showing E1\n");
  display(&e1);
  printf("Showing E2\n");
  display(&e2);

  return 0;
}
