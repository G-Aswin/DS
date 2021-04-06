/*
12.
Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine
the records in file F.

 Assume that file F is maintained in memory by a Hash Table (HT) of m
memory locations with L as the set of memory addresses (2-digit) of locations in HT. 

// hence each element of hash table contains 1. key, 2. Address in file where that key is stored.

Let the keys in K and addresses in L are Integers.
 Design and develop a Program in C that uses 
 Hash function H: K →L as H(K)=K mod m (remainder method),
 and implement hashing technique to map a given key K to the address space L.

 // so K is the set of keys (empno), L is the hashed value (hash_idx).

 Resolve the collision (if any) using linear probing.

*/




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

//Hash function
int hash(int key)
{
    //Division hashing
    return key % HZ;
}


// Helper functions

//Function to insert N employees into the FILE and store their info in the hashtable.
//1. Input the employee struct
//2. Hash the empno. Linear Probe till an empty spot is found
//3. Seek to EOF and store that address into hashtable hashidx
//4. Write the struct inside the file and done.
void insert(FILE *fp, int n)
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

//Display the whole set of information.
void display(FILE *fp)
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


//Finding a specific employee in the hash table.
void search(FILE *fp)
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

    printf("E-No : %d\nE-name : %s\nSalary : %d\n\n", emp.empno, emp.name, emp.sal);
}




int main()
{
    fp = fopen("employees.txt", "w+");
    int ch, n;
    while(1)
    {
        printf("\n1. Insert N employees in the file \n2. Display the whole hash table \n3. Search for an employee\n\n: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: printf("Enter the number of employees : ");
                    scanf("%d", &n);
                    insert(fp, n);
                    break;

            case 2: display(fp);
                    break;
            
            case 3: search(fp);
                    break;
            
            default:fclose(fp); 
                    return 0;
        }
    }
}