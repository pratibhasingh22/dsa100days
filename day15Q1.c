#include<stdio.h>
int main(){
    int m,n;
    printf("enter the rows and columns of the matrix");
    scanf("%d %d",&m,&n);

    int mat[m][n];
    int sum=0;
    printf("the elements of the matrix are");

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=mat[i][j];
            }
        }
        
    }
    printf("%d\n",sum);
    return 0;

}