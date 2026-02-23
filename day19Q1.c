#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    int arr[n];

    printf("enter the elements are");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    
    int minSum=arr[0] + arr[1];
    int num1=arr[0],num2=arr[1];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            if(abs(sum)<abs(minSum)){
                minSum=sum;
                num1=arr[i];
                num2=arr[j];

            }
        }
    }
    printf("%d %d",num1,num2);
    return 0;
}
