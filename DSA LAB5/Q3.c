#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row, col, val;
};

struct colHead
{
    int col;
    struct colHead *next;
};

struct rowHead
{
    int row;
    struct rowHead *next;
};

struct sparsehead
{
    int rowCount, colCount;
    struct rowHead *frow;
    struct colHead *fcol;
};

struct sparse
{
    int row, *data;
    struct sparsehead *smatrix;
    struct rowHead **rowPtr;
    struct colHead **colPtr;
};

int count = 0;

void initialize(struct sparse *sPtr, int row, int col)
{
    int i;
    sPtr->rowPtr = (struct rowHead **)calloc(1, (sizeof(struct rowHead) * row));
    sPtr->colPtr = (struct colHead **)calloc(1, (sizeof(struct colHead) * col));
    for (i = 0; i < row; i++)
        sPtr->rowPtr[i] = (struct rowHead *)calloc(1, sizeof(struct rowHead));

    for (i = 0; i < row - 1; i++)
    {
        sPtr->rowPtr[i]->row = i;
        sPtr->rowPtr[i]->next = sPtr->rowPtr[i + 1];
    }

    for (i = 0; i < col; i++)
        sPtr->colPtr[i] = (struct colHead *)calloc(1, sizeof(struct colHead));

    for (i = 0; i < col - 1; i++)
    {
        sPtr->colPtr[i]->col = i;
        sPtr->colPtr[i]->next = sPtr->colPtr[i + 1];
    }
    sPtr->smatrix = (struct sparsehead *)calloc(1, sizeof(struct sparsehead));
    sPtr->smatrix->rowCount = row;
    sPtr->smatrix->colCount = col;
    sPtr->smatrix->frow = sPtr->rowPtr[0];
    sPtr->smatrix->fcol = sPtr->colPtr[0];
    return;
}
void inputMatrix(struct sparse *sPtr, int row, int col)
{
    int i, n, x = 0, y = 0;
    n = row * col;
    sPtr->data = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        if (y != 0 && y % col == 0)
        {
            x++;
            y = 0;
        }
        printf("data[%d][%d] : ", x, y);
        scanf("%d", &(sPtr->data[i]));
        if (sPtr->data[i])
            count++;
        y++;
    }
    return;
}
void displayInputMatrix(struct sparse s, int row, int col)
{
    int i;
    for (i = 0; i < row * col; i++)
    {
        if (i % col == 0)
            printf("\n");
        printf("%d ", s.data[i]);
    }
    printf("\n");
    return;
}

int main()
{
    struct sparse input, output;
    int row, col, spcheck;
    printf("Enter the rows and columns:");
    scanf("%d%d", &row, &col);
    initialize(&input, row, col);
    initialize(&output, row, col);
    inputMatrix(&input, row, col);
    printf("Given Sparse Matrix has %d non-zero elements\n", count);
    spcheck = 0.5 * row * col;
    if (count < spcheck)
    {
        printf("Input Sparse Matrix:\n");
        displayInputMatrix(input, row, col);
    }
    else
    {
        printf("Entered Matrix is not sparse matrix");
        displayInputMatrix(input, row, col);
    }
    printf("\n");
    return 0;
}
