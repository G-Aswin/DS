#include <stdio.h>

int linear_search(int arr[], int n, int key){

    for(int i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return 0;
}

int main()
{
    int n, key, arr[20];
    printf("Enter the size of the array  : ");
    scanf("%d", &n);

    printf("\nEnter the elements of the array : ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n Enter the element you want to search  : ");
    scanf("%d", &key);

    int result = linear_search(arr, n, key);

    if (result == 0){
        printf("\n The key wasn't found!\n");
    }
    else
    {
        printf("\n They key %d was found @ index %d.\n", key, result);
    }
    
    return 0;
}