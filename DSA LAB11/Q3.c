//Delete BST Non - Recursive
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *insert_nrec(struct node *root, int ikey);
struct node *del_nrec(struct node *root, int dkey);
struct node *case_c(struct node *root, struct node *par, struct node *ptr);
struct node *case_b(struct node *root, struct node *par, struct node *ptr);
struct node *case_a(struct node *root, struct node *par, struct node *ptr);
void display(struct node *ptr, int level);
int main()
{
    struct node *root = NULL, *ptr;
    int choice, k, i, n = 5;
    printf("\nEnter N value: ");
    scanf("%d", &n);
    printf("Enter the key to be inserted : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        root = insert_nrec(root, k);
    }
    printf("\n");
    display(root, 0);
    printf("\n");
    printf("Enter the key to be deleted Non - Recursively : ");
    scanf("%d", &k);
    root = del_nrec(root, k);
    printf("\n");
    display(root, 0);
    printf("\n");
}
struct node *insert_nrec(struct node *root, int ikey)
{
    struct node *tmp, *par, *ptr;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (ikey < ptr->info)
            ptr = ptr->lchild;
        else if (ikey > ptr->info)
            ptr = ptr->rchild;
        else
        {
            printf("Duplicate key");
            return root;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = ikey;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
        root = tmp;
    else if (ikey < par->info)
        par->lchild = tmp;
    else
        par->rchild = tmp;
    return root;
}
struct node *del_nrec(struct node *root, int dkey)
{
    struct node *par, *ptr;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (dkey == ptr->info)
            break;
        par = ptr;
        if (dkey < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }
    if (ptr == NULL)
        printf("dkey not present in tree\n");
    else if (ptr->lchild != NULL && ptr->rchild != NULL)
        root = case_c(root, par, ptr);
    else if (ptr->lchild != NULL)
        root = case_b(root, par, ptr);
    else if (ptr->rchild != NULL)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);
    return root;
}
struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if (par == NULL)
        root = NULL;
    else if (ptr == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
    free(ptr);
    return root;
}
struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child;
    if (ptr->lchild != NULL)
        child = ptr->lchild;
    else
        child = ptr->rchild;

    if (par == NULL)
        root = child;
    else if (ptr == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while (succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }

    ptr->info = succ->info;

    if (succ->lchild == NULL && succ->rchild == NULL)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr == NULL)
        return;
    else
    {
        display(ptr->rchild, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->info);
        display(ptr->lchild, level + 1);
    }
}