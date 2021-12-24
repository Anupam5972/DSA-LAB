// Return the lowest common ancestor(LCA) if node values are given for a tree.
#include <stdio.h>
#include <stdlib.h>
#define COUNT 7
struct node
{
    int data;
    struct node *left, *right;
};
struct node *lca(struct node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data > n1 && root->data > n2)
            root = root->left;
        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else
            break;
    }
    return root;
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void print2DUtil(struct node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->left, space);
};
void print2D(struct node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    print2D(root);
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    n1 = 10, n2 = 12;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}