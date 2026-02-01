#include<stdio.h>
int  main(){
    int n,pos,x;
    int arr[100];

    printf("enter the number of elements in the array");
    scanf("%d",&n);
    
    printf("enter the elements");
    for(int i=0;i<n;i++){
        //printf("enter the elements");
        scanf("%d",&arr[i]);
    }
    printf("enter the position where to insert");
    scanf("%d",&pos);

    printf("enter the element to insert");
    scanf("%d",&x);

    for(int i=n;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    
    arr[pos-1]=x;

    for(int i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}