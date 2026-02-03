#include<stdio.h>
int main(){
    int n,k,found=0,comparisons=0;
    printf("enter the no of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the element to find");
    scanf("%d",&k);

    for(int i=0;i<n;i++){
        comparisons++;
        if(arr[i]==k){
            printf("found at index %d\n",i);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("element not found");
    }
    printf("no of comparisons done are %d",comparisons);
    return 0;
}