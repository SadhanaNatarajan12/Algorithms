/* Given an unsorted integer array, find the smallest missing positive integer.
Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note: Your algorithm should run in O(n) time and uses constant extra space.
*/

#include <iostream>

void swap(int arr[], int i, int j)
{
    std::cout<<"swap i = "<<i<<" j = "<<j<<std::endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findMissingPositiveInt(int arr[], int nsize)
{
    if (nsize == 0 || nsize < 2)
	return -1;

    for (int i = 0; i <= nsize - 1; ) {
	if (arr[i] <= 0 || arr[i] > nsize || arr[i] - 1 == i) {
	    i++;
	} else {
	    swap(arr, i, arr[i] - 1);
	}
    }

    for (int i = 0; i <= nsize - 1; i++) {
	if (arr[i] - 1 != i) {
	    return i + 1;
	}
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 0};
    int nsize = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Input = {1, 2, 0}, nsize = 3"<<std::endl;
    std::cout<<"Missing +ve num: "<<findMissingPositiveInt(arr, nsize)<<std::endl;

    int arr1[] = {3, 4, -1, 1};
    int nsize1 = sizeof(arr1)/sizeof(arr1[0]);
    std::cout<<"Input = {3, 4, -1, 1}, nsize = 4"<<std::endl;
    std::cout<<"Missing +ve num: "<<findMissingPositiveInt(arr1, nsize1)<<std::endl;

    int arr2[] = {7, 8, 9, 11, 12};
    int nsize2 = sizeof(arr2)/sizeof(arr2[0]);
    std::cout<<"Input = {7, 8, 9, 11, 12}, nsize = 5"<<std::endl;
    std::cout<<"Missing +ve num: "<<findMissingPositiveInt(arr2, nsize2)<<std::endl;

    int arr3[] = {4, 3, 2, 0};
    int nsize3 = sizeof(arr3)/sizeof(arr3[0]);
    std::cout<<"Input = {4, 3, 2, 0}, nsize = 4"<<std::endl;
    std::cout<<"Missing +ve num: "<<findMissingPositiveInt(arr3, nsize3)<<std::endl;
}
