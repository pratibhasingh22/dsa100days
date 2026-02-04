#include<stdio.h>
int main(){
    int n;
    printf("enter the no of element of the array");
    scanf("%d",&n);

    int arr[n];
    printf("enter the elements of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    int left=0,right=n-1;
    while(left<right){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;

    }
    printf("reversed array\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);

    }
    return 0;

}