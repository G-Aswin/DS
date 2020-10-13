#include <stdio.h>

typedef struct emp
{
  char name[20];
  int age;
  float salary;
}E;


int main() {

  E e[3];

  for (int i = 0; i < 3; i ++){
    printf("Enter Details for %d struct\n", i + 1);
    scanf("%s%d%f", e[i].name, &e[i].age, &e[i].salary);
  }


  for (int i = 0; i < 3; i ++){
      printf("Printing Details for %d struct\n", i + 1);
      printf("%s %d %f\n", e[i].name, e[i].age, e[i].salary);
    }


  return 0;
}
