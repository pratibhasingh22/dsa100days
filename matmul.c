#include<stdio.h>
int main(){
    int r1,c1,r2,c2;
    while(1){
        printf("enter the number of rows and columns of mat1:");
        scanf("%d %d",&r1,&c1);
        printf("enter the no of columns and row of mat2:");
        scanf("%d %d",&r2,&c2);
        if(c1==r2){
            break;
        }
        else{
            printf("multiplication  allowed only if c1==r2\n");
            printf("please enter again\n");

        }
    }
    int mat1[r1][c1];
    int mat2[r2][c2];
    int result[r1][c2];
    printf("enter the elements of the first matrix\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("enter elements of the second matrix\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            result[i][j]=0;
            for(int k=0;k<c1;k++){
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("resultant mat\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");

    }
    return 0;
}
