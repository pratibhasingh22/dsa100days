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
            printf("addition allowed only if rows=columns\n");
            printf("please enter again\n");

        }
    }
    int mat1[m][n];
    int mat2[m][n];
    int result[m][n];
    printf("enter the elements of the first matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("enter elements of the second matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;i<n;j++){
            result[i][j]=mat1[i][j]+mat2[i][j];
        }

    }
    printf("the resultant matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",result[i][j]);

        }
        printf("\n");
    }
    return 0;
}
