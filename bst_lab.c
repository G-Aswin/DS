// 10. Design, Develop and Implement a menu driven Program in C for the
// following operations on
// Binary Search Tree (BST) of Integers .

// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2

// b. Traverse the BST in Inorder, Preorder and Postorder

// c. Search the BST for a given element (KEY) and report the appropriate
// message

// d. Exit


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node * NODE;

NODE getnode()
{
    NODE x = (NODE) malloc(sizeof(struct node));
    
    if (x == NULL)
        exit(0);

    return x;
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

void preorder_iterative(NODE root)
{
    NODE stack[20], curr;
    int top = -1;

    if (root == NULL)
        return;

    curr = root;
    while(1)
    {
        while(curr != NULL)
        {
            printf("%d ", curr->info);
            stack[++top] = curr;
            curr = curr->left;
        }
        if (top != -1)
        {
            curr = stack[top--];
            curr = curr->right;
        }
        else
            return;
    }
}

void inorder_iterative(NODE root)
{
    NODE stack[20], curr;
    int top = -1;

    if (root == NULL)
        return;

    curr = root;
    while(1)
    {
        while(curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        if (top != -1)
        {
            curr = stack[top--];
            printf("%d ", curr->info);
            curr = curr->right;
        }
        else
            return;
    }
}

void postorder_iterative(NODE root)
{
    NODE stack[20], curr;
    int top = -1;

    if (root == NULL)
        return;

    curr = root;
    while(1)
    {
        while(curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        if (top != -1)
        {
            printf("%d ", stack[top]->info);
            curr = stack[top--];
            curr = curr->right;
        }
        else
            return;
    }
}

NODE insert(NODE root, NODE new)
{
    if (root == NULL)
        return new;

    if (new->info > root->info)
        root->right = insert(root->right, new);

    else if (new->info < root->info)
        root->left = insert(root->left, new);

    else
        free(new);  

    return root;   
}



int search(NODE root, int target, int flag)
{
    if (root == NULL)
        return flag;
    
    if (root->info == target)
    {
        printf("\nFound the target");
        return 1;
    }
    else if (target < root->info)
        return search(root->left, target, flag);
    else if (target > root->info)
        return search(root->right, target, flag); 

}


void search_iterative(NODE root, int target)
{
    if (root == NULL)
    {
        printf("Nothing in the tree\n");
        return;
    }    

    while (root != NULL)
    {
        if (root->info == target)
        {
            printf("The element is found!");
            return;
        }
        else if (target < root->info)
            root = root->left;
        else
            root = root->right;
    }

    printf("Element was not found!\n");
    return;
}   






int main()
{
    NODE root = NULL;
    int ch, target, n = 0, x;

    while (1)
    {
        printf("\n\n1.Inorder\n2. preorder\n3. postorder\n4. Search\n5. Insert\n\n");
        printf("6. Preorder Iter\n7. Inorder iter\n8.PostOrder iter\n\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: inorder(root);   
                    break;
            case 2: preorder(root);   
                    break;
            case 3: postorder(root);                     
                    break;
            case 4: printf("Enter the number : ");
                    scanf("%d", &target); 
                    search_iterative(root, target);   
                    break;
            case 5:
                    printf("Enter the number of nodes to be inserted : ");
                    scanf("%d", &n);
                    root = NULL;
                    for (int i = 0; i < n; i++)
                    {
                        printf("Info of Node number %d : ", i);
                        scanf("%d", &x);
                        NODE new = getnode();
                        new->info = x;
                        new->right = new->left = NULL;
                        root = insert(root, new);
                    }
                    break;

            case 6: preorder_iterative(root);
                    break;
            
            case 7: inorder_iterative(root);
                    break;

            case 8: postorder_iterative(root);
                    break;

                    
            default: return 0;
        }
    }



}