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
    struct stack
    {
        NODE address;
        int flag;
    };
    
    struct stack s[10];
    int top = -1;

    if (root == NULL)
    {
        printf("The tree is empty!\n");
        return;
    }

    NODE curr = root;

    while (1)
    {
        // Traversing Left
        while (curr != NULL)
        {
            ++top;
            s[top].address = curr;
            s[top].flag = 1;
            curr = curr->left;
        }

        //If left right both processed, process
        while(s[top].flag < 0)
        {
            curr = s[top].address;
            top--;
            printf("%d ", curr->info);

            if (top == -1)
                return;
        }

        //Only left processed so process right.
        curr = s[top].address;
        curr = curr->right;
        s[top].flag = -1;
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



NODE search(NODE root, int target)
{
    
    if (root == NULL || root->info == target)
        return root;

    else if (target < root->info)
        return search(root->left, target);

    else if (target > root->info)
        return search(root->right, target); 

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

NODE delete(NODE root, int item)
{
    NODE cur=root,parent=NULL,suc,min_par,pos_del;
    if(cur==NULL)
    {
        printf("TREE IS EMPTY!\n");
        return root;
    }
    while(cur!=NULL)
    {
        if(item==cur->info)
            break;
        parent=cur;
        if(item<cur->info)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(cur->left==NULL && cur->right==NULL)
    {
        if (parent == NULL)
        {
            free(cur);
            return NULL;
        }
        if(parent->right==cur)
            parent->right=NULL;
        else
            parent->left=NULL;
        printf("Node to be deleted %d",cur->info);
        free(cur);
        return root;
    }
    if(cur->left==NULL || cur->right==NULL)
    {
            if(cur->left==NULL)
                suc=cur->right;
            else
                suc=cur->left;

            if (parent == NULL)
            {
                free(cur);
                return suc;
            }

            if(parent->left==cur)
                 parent->left=suc;
            else
                parent->right=suc;
        printf("Node to be deleted %d",cur->info);
        free(cur);
        return root;
    }
    pos_del=cur;
    // min_par=cur;
    cur=cur->right;
    while(cur->left!=NULL)
    {
        // min_par=cur;
        cur=cur->left;
    }
    // suc=cur->right;
    // if(min_par->left==cur)
    //     min_par->left=suc;
    // else
    //     min_par->right=suc;
    pos_del->info=cur->info;
    printf("Node to be deleted %d",pos_del->info);
    delete(pos_del->right, cur->info);
    return root;
}


// NODE delete(NODE root, int target)
// {
//     if (root == NULL)
//     {
//         printf("The tree is empty!\n");
//         return root;
//     }

//     // Get to the target while saving the parent;
//     NODE curr = root, parent = NULL;
//     while(curr != NULL)
//     {
//         if (curr->info == target)
//             break;

//         parent = curr;
        
//         if (target < curr->info)
//             curr = curr->left;
//         else
//             curr = curr->right;
//     }

//     if (curr == NULL)
//     {
//         printf("The target is unavailable in this tree\n");
//         return root;
//     }

//     if (curr->left == NULL && curr->right == NULL)
//     {
//         if (parent == NULL)
//             return NULL;

//         if (parent->left == curr)
//             parent->left = NULL;
//         else
//             parent->right = NULL;

//         free(curr);
//         return root;      
//     }
    
//     NODE successor;

//     if (curr ->left == NULL || curr->right == NULL)
//     {
//         if (curr->left == NULL)
//             successor = curr->right;
//         else
//             successor = curr->left;

//         if (parent == NULL)
//         {
//             free(curr);
//             return successor;
//         }

//         if (parent->left == curr)
//             parent->left = successor;
//         else
//             parent->right = successor;

//         free(curr);
//         return root;
//     }

//     NODE pos_del = curr, min_parent = curr;
//     curr = curr->right;
//     while(curr->left != NULL)
//     {
//         min_parent = curr;
//         curr = curr->left;
//     }

//     successor = curr->right; // can either be right subtree or NULL
//     if (min_parent->left == curr)
//         min_parent->left = successor;
//     else
//         min_parent->right = successor;

//     pos_del->info = curr->info;
//     free(curr);
//     return root;
// }





int main()
{
    NODE root = NULL;
    int ch, target, n = 0, x;

    while (1)
    {
        printf("\n\n1.Inorder\n2. preorder\n3. postorder\n4. Search\n5. Insert\n\n");
        printf("6. Preorder Iter\n7. Inorder iter\n8.PostOrder iter\n9. Delete\n\n");
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

            case 9: printf("Enter the number to be deleting : ");
                    scanf("%d", &target);
                    delete(root, target);
                    break;

                    
            default: return 0;
        }
    }



}