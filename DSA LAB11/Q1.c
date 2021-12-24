// Delete BST Recursive
#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE *createtree(NODE *node, int data)
{
    if (node == NULL)
    {
        NODE *temp;
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data))
    {
        node->left = createtree(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = createtree(node->right, data);
    }
    return node;
}
void inorder(NODE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}
NODE *findMin(NODE *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left)
        return findMin(node->left);
    else
        return node;
}
NODE *findMax(NODE *node)
{
    NODE *current = node;
    while (current->right != NULL)
        current = current->right;
    return node;
}
NODE *del(NODE *node, int data)
{
    NODE *temp;
    if (node == NULL)
    {
        printf("\nElement not found");
    }
    else if (data < node->data)
    {
        node->left = del(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = del(node->right, data);
    }
    else
    {
        if (node->right && node->left)
        {
            temp = findMin(node->right);
            node->data = temp->data;
            node->right = del(node->right, temp->data);
        }
        else
        {
            temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}
int main()
{
    int data, ch, i, n;
    NODE *root = NULL;
    printf("\nEnter N value: ");
    scanf("%d", &n);
    printf("\nEnter the values to create BST\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = createtree(root, data);
    }
    printf("\nInorder Arrangement of BST: \n");
    inorder(root);
    printf("\nEnter the element to delete Recursively: ");
    scanf("%d", &data);
    root = del(root, data);
    printf("\nInorder Arrangement of BST: \n");
    inorder(root);
}