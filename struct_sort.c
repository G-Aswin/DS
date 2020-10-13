#include <stdio.h>
#include <string.h>

typedef  struct emp
{
    int eid;
    char name[20];
    float sal;
} E;

void accept(E *t, int n)
{
    int i;
    printf("Enter the ele of the struct\n");
    
    for (i = 0; i < n; i++)
    {
        printf("\nStruct %d:\n", i + 1);
        scanf("%d%s%f", &(t[i].eid), t[i].name, &(t[i].sal));
    }
}


void display(E *t, int n)
{
    printf("\nElements of the struct are \n");
    for (int i = 0; i < n; i++)
    {
    printf("Eid = %d, Ename = %s, Esal = %f",
    t[i].eid, t[i].name, t[i].sal);
    printf("\n");

    }
    
}



void merge(E *e, int start, int mid, int end, int option)
{
    int p = mid - start + 1;
    int q = end - mid;
    E e1[p];
    E e2[q];
    
    for (int i =start, j = 0; i <= end; i++, j++)
    {
        if (i <= mid)
        {
            e1[j]= e[i];
        }
        else{
            e2[j - p] = e[i];
        }
    }
    
    int i = 0, j = 0;
    int k = start;
    
    while(i < p && j < q)
    {
        if (option == 1)
        {
            if (e1[i].eid < e2[j].eid)
            {
                e[k] = e1[i];
                i++;
            }
            else{
                e[k] = e2[j];
                j++;
            }
            
            k++;
        }
        else if (option == 2)
        {
            if (strcmpi(e1[i].name, e2[j].name) < 0)
            {
                e[k] = e1[i];
                i++;
            }
            else{
                e[k] = e2[j];
                j++;
            }
            
            k++;
        }
        else if (option == 3)
        {
            if (e1[i].sal < e2[j].sal)
            {
                e[k] = e1[i];
                i++;
            }
            else{
                e[k] = e2[j];
                j++;
            }
            
            k++;
        }
        
    }
    
    while(i < p)
    {
        e[k] = e1[i];
        i++;
        k++;
    }
    
    while(j < q)
    {
        e[k] = e2[j];
        j++;
        k++;
    }
}



void sort_eid(E *e, int start, int end, int option)
{
    //merge sort
    if (start < end){
        int mid = (start+end)/2;
        sort_eid(e, start, mid, option);
        sort_eid(e, mid + 1, end, option);
        merge(e, start, mid, end, option);
    }
    
}






int main()
{
    E e[10];
    int n = 3, option = 0;
    accept(e, n);
    display(e, n);

    while(option != 4)
    {
        printf("\nWhich Parameter do you wanna sort with?\n");
        printf("1.Eid\n2.Name\n3.Salary4.Exit\n->");
        if (option == 4)
        {
            return 0;
        }
        scanf("%d", &option);
        sort_eid(e, 0, n - 1, option);
        display(e, n);
    }
    return 0;
}

