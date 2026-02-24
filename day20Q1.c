#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    printf("enter the elements of the array");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];

            if(sum==0){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}