#include <stdio.h>
#include <stdlib.h>

#define HZ 3

FILE *fp;

struct employee
{
    int empno;
    char name[20];
    int sal;
};
typedef struct employee EMP;

//each hash table element
struct hashtable
{
    int key;
    long int address;
};
typedef struct hashtable ht;

//Actual hash table
ht table[HZ] = {{-1, 0}};

int hash(int key)
{
    //Division hashing
    return key % HZ;
}


void insert(FILE *fp, int *h, int n)
{
    EMP emp;
    int hash_idx, original_hash;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Eno, Name and Salary for one emp : ");
        scanf("%d %s %d", &emp.empno, emp.name, &emp.sal);

        original_hash = hash_idx = hash(emp.empno);

        //Linear Probing
        while(table[hash_idx].key != -1)
        {
            hash_idx = (hash_idx + 1) % HZ;
            //We made a full cycle
            if (hash_idx == original_hash)
            {
                printf("No more space in hash table\n");
                return;
            }
        }

        table[hash_idx].key = emp.empno;
        fseek(fp, 0, SEEK_END);
        table[hash_idx].address = ftell(fp);
        fwrite(&emp, sizeof(EMP), 1, fp);
        printf("Entry for %d was successful\n", emp.empno);
    }
}

void display(FILE *fp, ht table[])
{
    EMP emp;
    for (int i = 0; i < HZ; i++)
    {
        if(table[i].key != -1)
        {
            fseek(fp, table[i].address, SEEK_SET);
            fread(&emp, sizeof(EMP), 1, fp);
            printf("E-ID : %d\nE-name : %s\nSalary : %d\n\n", emp.empno, emp.name, emp.sal);
        }
    }
}

void search(FILE *fp, ht table[])
{
    EMP emp;
    printf("Enter the E-no to be searched : ");
    scanf("%d", &emp.empno);

    int original_hash = hash(emp.empno);
    int hash_idx = original_hash;

    while(table[hash_idx].key != emp.empno)
    {
        hash_idx = (hash_idx + 1) % HZ;
        if (original_hash == hash_idx || table[hash_idx].key == -1)
        {
            printf("Not Found!");
            return;
        }
    }

    fseek(fp, table[hash_idx].address, SEEK_SET);
    fread(&emp, sizeof(EMP), 1, fp);

    printf("E-No : %d\nE-name : &s\nSalary : %d\n\n", emp.empno, emp.name, emp.sal);
}

