/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
int main(){
    int n,i,arr[100];
    printf("enter the no. of elements: ");
    scanf("%d",&n);
    printf("enter the elements of the array in a sorted manner: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int j=1;
    for(i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
           arr[j]=arr[i];
            j++;
        }
    }
    n=j;
    printf("array with unique elements: ");
    for(i=0;i<j;i++){
        printf("%d",arr[i]);
    }
    return 0;
}