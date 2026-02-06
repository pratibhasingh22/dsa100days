#include<stdio.h>
int main(){
    int n;
    printf("enter the no of values");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int dup=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                dup=1;
                break;
            }
        }
        if(!dup){
            printf("%d ",arr[i]);
        }
    }
    return 0;

}