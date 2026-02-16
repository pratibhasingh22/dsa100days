#include<stdio.h>
int main(){
    int n;
    printf("enter the no");
    scanf("%d",&n);

    int mat[n][n];
    int isidentity=1;
    printf("enter the elements of the array");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                if(mat[i][j]!=1){
                    isidentity=0;
                    break;

                }
            }
            else{
                 if(mat[i][j]!=0){
                    isidentity=0;
                    break;
                 }
            }
        }
        if(isidentity==0)
        break;
    }
    if(isidentity){
        printf("identity matrix");
    }
    else{
        printf("not a identity matrix");
    }
    return 0;
}