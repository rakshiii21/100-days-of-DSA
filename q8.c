/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>
int main(){
    int a,b,exp=1;
    printf("enter the number you want to increase the power of: ");
    scanf("%d",&a);
    printf("enter the no. by which you want to increase the power: ");
    scanf("%d",&b);
    for(int i=0;i<b;i++){
    exp*a;
    exp=exp*a;
}
printf("%d",exp);
return 0;
}