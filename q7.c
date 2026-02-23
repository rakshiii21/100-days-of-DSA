/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/
#include <stdio.h>
int main(){
    int n,fib,a=0,b=1,i;
    printf("enter the no. of term you want to see: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    fib=a+b;
    b=a;
    a=fib;
    }
    printf("%d",fib);
    return 0;
}