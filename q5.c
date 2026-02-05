/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>
int main(){
    int n1,n2,i,arr1[100],arr2[100];
    printf("enter the no. of entries in server log 1: ");
    scanf("%d",&n1);
    printf("enter arrival times from server 1 in a sorted manner: ");
    for(i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("enter the no. of entries in server log 2: ");
    scanf("%d",&n2);
    printf("enter arrival times from server 2 in a sorted manner: ");
    for(i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
   for(i=0;i<n2;i++){
    arr1[n1+i]=arr2[i];
   }
   int total=n1+n2;
   for(i=0;i<total-1;i++){
    for(int j=0;j<total-i-1;j++){
        if(arr1[j]>arr1[j+1]){
            int temp=arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=temp;
        }
    }
   }
   for(i=0;i<total;i++){
    printf("%d ",arr1[i]);
   }
    return 0;
}