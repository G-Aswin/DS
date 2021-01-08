// BST Insertion

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

NODE insert_bst(NODE node, NODE root)
{
    if (root == NULL)
        return node;
        
    if (node->info < root->info)
        root->left = insert_bst(node, root->left);
    else
        root->right = insert_bst(node, root->right);

    return root;
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
        inorder(root->left);
    printf("%d\n", root->info);
    if (root->right != NULL)
        inorder(root->right);
}

int main()
{
    NODE root = NULL;
    int list[] = {55,44,66,33,58,22,77,38,68};
    for (int i = 0; i < 9; i++)
    {
        NODE node = getnode();
        node->right = node->left = NULL;
        node->info = list[i];
        root = insert_bst(node, root);
    }
    inorder(root);
}