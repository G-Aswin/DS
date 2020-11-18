#include<stdio.h>
#include<stdlib.h>

//1. Linear Search

int linear_search(int arr[], int n, int key){

    for(int i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return 0;
}


//2. Convert Decimal into Binary

int decimal_to_binary(int decimal){
    int ans = 0;
    
    while (decimal != 0){
        ans = ans*10 + (decimal % 2);
        decimal /= 2;
    }

    return ans;
}

//3. Find Largest of three numbers

int largest_of_three_2(int a, int b, int c){

    if (a > b && a > c){
        return a;
    }
    else if (b > c){      
        return b;
    }
    else{
        return c;
    }
}

int largest_of_three_1(int a, int b, int c){

    if (a > b){
        if (a > c){
            return a;
        }
        else{
            return c;
        }
    }
    else{
        if (b > c){
            return b;
        }
        else
        {
            return c;
        }
    }
}
//4. Write a program to perform matrix addition

int** matrix_addition(int **a, int **b, int m, int n){ // Assuming that the dimension of both are same

    int **ans = malloc(sizeof(int)*(m*n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ans[i][j] = a[i][j] + b[i][j];
        }
    }

    return ans;
}


//5. Reverse a number

int reverse_a_number(int x){
    int ans = 0;
    
    while(x != 0){
        ans = ans*10 + (x % 10);
        x /= 10;
    }

    return ans;
}

int reversDigits(int num) 
{ 
static int rev_num = 0; 
static int base_pos = 1; 
if(num > 0) 
{ 
    reversDigits(num/10); 
    rev_num += (num%10)*base_pos; 
    base_pos *= 10; 
} 
return rev_num; 
} 


// Tester function

int main()
{
    printf("The reverse of %07d is %d", 69420, reversDigits(69420));
    return 0;
}