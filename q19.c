/*/Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Using simple array as hash map (range assumed manageable)
    int freq[20001] = {0};  
    int offset = 10000;  // To handle negative sums

    freq[offset] = 1;  // For prefix sum = 0

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If this prefix sum appeared before
        count += freq[prefixSum + offset];

        // Increase frequency
        freq[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
