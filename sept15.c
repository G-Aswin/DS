#include <stdio.h>
#include <stdlib.h>


void accept(int *b, int n){
	int i;

	printf("\n Enter the elements : ");

	for (i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
}

void display(int *c, int n){
	int i;

	printf("\n ELements of the array are : ");

	for (i = 0; i < n; i++){
		printf("%d ", c[i]);
	}

	printf("\n");
}



int main()
{
	int a[20], n;
	printf("Enter size of the array a : ");
	scanf("%d", &n);
	accept(a, n);
	display(a, n);

	return EXIT_SUCCESS;
} 
