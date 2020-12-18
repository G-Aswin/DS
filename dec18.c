// Polynomial addition using CSLL with header

//Algorithm
//1. Take two CLL-H P1 and P2, scanf the two polynomials (read_poly)
//2. Go term by term of P1, check if theres a matching term in P2 (compare)
//3. If there is, add the coeff and insert into P3, mark the found term with 999
//4. If there's no matching, add the P1 term alone
//5. Insert all the remaining terms in P2 into P3

#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int cf, px, py, pz;
    struct poly *link;
};
typedef struct poly * P;

P getnode()
{
    P x = (P)malloc(sizeof(struct poly));
    if (x == NULL)
        exit(0);
    return x;
}

void read_poly(P p, int n)
{
    P new;
    while (n--)
    {
        new = getnode();
        printf("\nEnter the CF, PX, PY and PZ respectively : ");
        scanf("%d %d %d %d", &new->cf, &new->px, &new->py, &new->pz);

        new->link = p->link;
        p->link = new;
    }
}

void display_poly(P p)
{
    if (p->link == p)
        return;

    P curr = p->link;
    while (curr != p)
    {
        if (curr->cf >= 0)
            printf("+ %dx^%dy^%dz^%d ", curr->cf, curr->px, curr->py, curr->pz);
        else
            printf("%dx^%dy^%dz^%d ", curr->cf, curr->px, curr->py, curr->pz);
        curr = curr->link;
    }
}

P compare_term(P term, P p2)
{
    if (p2->link == p2)
        return NULL;

    P curr = p2->link, prev = p2;
    while(curr != p2)
    {
        if (curr->px == term->px && curr->py == term->py && curr->pz == term->pz)
        {
            prev->link = curr->link;
            return curr;
        }
        prev = curr;
        curr = curr->link;
    }
    return NULL;
}

void insert_into_front(P head, int cf, int px, int py, int pz)
{
    P node = getnode();
    node->cf = cf;
    node->px = px;
    node->py = py;
    node->pz = pz;

    node->link = head->link;
    head->link = node;
    return;
}

int main()
{
    P p1 = getnode(), p2 = getnode(), p3 = getnode();
    p1->link = p1; p2->link = p2; p3->link = p3;
    int m, n;

    printf("\nNumber of terms in p1 : ");
    scanf("%d", &m);
    read_poly(p1, m);

    printf("\nNumber of terms in p2 : ");
    scanf("%d", &n);
    read_poly(p2, n);

    // Go through each p1 term
    P curr = p1->link;
    P response = NULL;

    while (curr != p1)
    {
        response = compare_term(curr, p2);
        if (response == NULL)
            insert_into_front(p3, curr->cf, curr->px, curr->py, curr->pz);
        else
            insert_into_front(p3, curr->cf + response->cf, curr->px, curr->py, curr->pz);

        curr = curr->link;
    }

    // Add remaining terms of p2
    curr = p2->link;
    while(curr != p2)
    {
        insert_into_front(p3, curr->cf, curr->px, curr->py, curr->pz);
        curr = curr->link;
    }

    printf("The final added polynomial is : ");
    display_poly(p3);
    
    return EXIT_SUCCESS;
}