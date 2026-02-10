#include<stdio.h>
int power(int a,int b){
    if (b==0)
      return 1;
    return a*power(a,b-1);  

}
int main(){
    int a,b;
    printf("enter the values of a and b");
    scanf("%d",&b);
    printf("%d",power(a,b));
    return 0;


}