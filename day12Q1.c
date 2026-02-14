#include<stdio.h>
int main(){
    int m,n;
    while(1){
        printf("enter the number of rows:");
        scanf("%d",&m);
        printf("enter the no of columns:");
        scanf("%d",&n);
        if(m==n){
            break;
        }
        else{
            printf("symmetry possible only if rows=columns\n");
            printf("please enter again\n");

        }
    }
    int arr[m][n];
    int i,j;
    printf("enter the matrix element\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);

        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=arr[j][i]){
                printf("not a symmetric matrix");
                return 0;
            }
        }
    }
    printf("symmetric matrix");
    return 0;
}    
