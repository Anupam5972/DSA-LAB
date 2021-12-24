#include <stdio.h>
int main() {
    
    int a[4][4], non0ctr = 0, leadingSum=0, majorProduct=1;
    printf("Enter a 4x4 matrix: ");
    for(int i =0; i<4;i++){
        for(int j = 0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i =0; i<4;i++){
        for(int j = 0;j<4;j++){
            if(a[i][j] != 0){
                non0ctr++;
            }
            if(i==j){
                leadingSum+=a[i][j];
                majorProduct *= a[i][j];
            }
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nnumber of non 0: %d", non0ctr); //non 0 counter
    printf("\nLeading Sum: %d", leadingSum); //Sum of elements for leading diagonal 
    printf("\nMinor elements: "); //display minor elements
    for(int i =0; i<4;i++){
        for(int j = 0;j<4;j++){
            if(i+j>3){
                printf("%d, ",a[i][j]);
            }
        }}
    printf("\nDiagonal elements Product: %d", majorProduct); //Product of elements on the diagonal
    return 0;
}
