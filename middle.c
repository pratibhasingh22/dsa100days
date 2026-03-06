#include<stdio.h>

int main(){
    int arr[50],n,i;
    printf("enter the no of elements");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    if(n%2!=0){
        printf("middle element =%d",arr[n/2]);

    }
    else{
        printf("middle elements=%d,%d",arr[(n/2)-1],arr[n/2]);

    }
    return 0;
    
}