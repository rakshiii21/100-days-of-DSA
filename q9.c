/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in 
the opposite order.
Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int i,j,temp;
    printf("enter code name you want to encrypt: ");
    for(i=0;i<=100;i++){
        scanf("%c",&str[i]);
        if(str[i]=='\n'){
            str[i]='\0';
            break;
        }
    }
    i=0;
    j=strlen(str)-1;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    printf("code name: %s",str);
    return 0;
}