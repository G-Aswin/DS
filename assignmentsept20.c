/* Dear students, instruct you to upload the following programs
1.	Write a menu driven program for the following operation in C
Accept the array elements
Accept elements in specific position
Delete elements from specific position
Display elements
2.	Write a program in c to perform array multiplication
3.	Write a program to find largest, second largest and first smallest and second smallest element in a array (int values)
4.	Write a program in c to remove duplicate elements in the array.
Note: 
Write programs using functions (accepting , display, or for specific task)
Execute and write the correct program (hand written) in A4 sheet, take */

//Question 1
#include<stdio.h>

void create_array(int *a, int *n){
    printf("\nEnter the number of elements to enter: ");
    scanf("%d", n);

    printf("\nEnter %d elements : \n", *n);
    for (int i = 0; i < *n; i++){
        scanf("%d", &a[i]);
    }

    return;
}

int insert_at(int *a, int n){

    int pos, ele;

    printf("\nEnter pos: ");
    scanf("%d", &pos);

    printf("\nEnter ele: ");
    scanf("%d", &ele);
    

    if (pos < 0 || pos > n){
        printf("\nPlease enter a valid index.\n");
        return n;
    }
    else if (pos == n){
        a[n] = ele;
        n++;
        return n;
    }

    int start = n, end = pos;

    while (start != end){
        a[start] = a[start - 1];
        start--;
    }

    a[pos] = ele;
    n++;

    printf("\nThe element has been added!\n");

    return n;
}

int delete_at(int *a, int n){

    int pos;

    printf("\nEnter pos: ");
    scanf("%d", &pos);


    if (pos < 0 || pos >= n){
        printf("\nPlease enter an invalid index!\n");
        return n;
    }

    if (pos == (n - 1)){
        n--;
        return n;
    }

    for (int i = pos; i < (n - 1); i++){
        a[i] = a[i + 1];
    }

    n--;
    
    printf("\nThe element is deleted!");
    return n;
}

void display(int *a, int n){
    if (n == 0){
        printf("\nPlease enter something into the array first!\n");
        return;
    }
    printf("\nArray : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return;
}

// int main(){
//     int a[20], n = 0, choice;

//     while(1){
//         printf("\nMENU\n\n1. Create Array\n2. Insert into Array\n3. Delete\n4.Display\n5.Exit Program\n\nEnter your choice : ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             create_array(a, &n);
//             break;
//         case 2:
//             n = insert_at(a, n);
//             break;
//         case 3:
//             n = delete_at(a, n);
//             break;
//         case 4:
//             display(a, n);
//             break;
//         case 5:
//             return 0;
//         default:
//             printf("\nIncorrect Choice Try again");
//             break;
//         }
//     }

//     return 0;
// }





// Largest, second largest, smallest, second smallest.

void top_two_bottom_two(int *a, int n)
{
    if (n < 4){
        printf("Not enough elements for the function\n");
        return;
    }

    int l1 = a[0], l2 = a[0], s1 = a[0], s2 = a[0];

    for (int i = 1; i < n; i++){
        if (a[i] > l1){
            l2 = l1;
            l1 = a[i];
        }
        if (a[i] < s1){
            s2 = s1;
            s1 = a[i];
        }
    }

    printf("\n Largest = %d\nSecond Largest = %d", l1, l2);
    printf("\n Smallest = %d\nSecond Smallest = %d", s1, s2);
}


// int main(){
//     int a[7] = {12, 11, 43, 45, 65, 34, 90};
//     top_two_bottom_two(a, 7);
//     return 0;
// }


// Delete Duplicate elements in an array


void delete_duplicate(int *a, int *n)
{
    int size = *n;
    int last_idx = size - 1;  // Points to the last element of the array.
    for (int i = 0; i < size - 1; i++)
    {
        for (int k = i + 1; k < size; k++)
        {
            if (a[k] == a[i])
            {
                int temp = a[last_idx];
                a[last_idx] = a[k];
                a[k] = temp;

                k--;        // To make sure our new swapped element also gets checked
                size--;     // Reducing size makes sure we ignore the element we just swapped aka duplicate
                last_idx--; // This now points to a new fresh element at the back ready to be swapped if some duplicate is found.
            }
        }
    }

    printf("\nNumber of elements deleted : %d\n", (*n) - size);
    *n = size;
}

int main(){
    int a[10] = {1,2,5,2,5,2,1,2,5,2}, n = 10;

    display(a, n);

    delete_duplicate(a, &n);

    printf("\nAfter deleting\n");

    display(a, n);
    
}