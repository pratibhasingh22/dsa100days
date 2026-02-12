#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int left=0;
    
    int flag=1;

    printf("enter the string");
    scanf("%s",str);
    int right=strlen(str)-1;
    while(left<right){
        if(str[left]!=str[right]){
            flag=0;
            break;
        }
        left++;
        right--;

    }
    if(flag)
      printf("palindrome");
    else
      printf("not a palindrome");
    return 0;  



}