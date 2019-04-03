/* Maximum sum subarray using kadanes algorithm
*/
#include <iostream>
int kadaneAlgoMaxSumSubArray(int arr[], int nsize, int &startIdx, int &endIdx)
{
    int max_sum_ending_here = arr[0];
    int max_sum_so_far = arr[0];

    int s = 0;
    startIdx = 0;
    endIdx = 0;

    for (int i = 1; i <= nsize - 1; i++) {
	max_sum_ending_here = max_sum_ending_here + arr[i];

	if (max_sum_so_far < max_sum_ending_here) {
	    max_sum_so_far = max_sum_ending_here;
	    startIdx = s;
	    endIdx = i;
	}

	if (max_sum_ending_here <= 0) {
	    max_sum_ending_here = 0;
	    s = i + 1;
	}
    }
    return max_sum_so_far;
}

int main()
{
    int arr[] = {1, -1, 3, 6, -2, -3};
    int nsize = sizeof(arr) / sizeof(arr[0]);
    int startIdx = 0, endIdx = 0;
    std::cout<<"Sum = "<<kadaneAlgoMaxSumSubArray(arr, nsize, startIdx, endIdx)<<" Start Idx = "<<startIdx<<" End Idx = "<<endIdx<<std::endl;



    int arr1[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int nsize1 = sizeof(arr1)/sizeof(arr1[0]);
    startIdx = 0, endIdx = 0;
    std::cout<<"Sum = "<<kadaneAlgoMaxSumSubArray(arr1, nsize1, startIdx, endIdx)<<" Start Idx = "<<startIdx<<" End Idx = "<<endIdx<<std::endl;

    int arr2[] = {10, -5, -4, -3, -7, -8, -1, -2, -6, -9};
    int nsize2 = sizeof(arr2)/sizeof(arr2[0]);
    startIdx = 0, endIdx = 0;
    std::cout<<"Sum = "<<kadaneAlgoMaxSumSubArray(arr2, nsize2, startIdx, endIdx)<<" Start Idx = "<<startIdx<<" End Idx = "<<endIdx<<std::endl;

    int arr3[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int nsize3 = sizeof(arr3)/sizeof(arr3[0]);
    startIdx = 0, endIdx = 0;
    std::cout<<"Sum = "<<kadaneAlgoMaxSumSubArray(arr3, nsize3, startIdx, endIdx)<<" Start Idx = "<<startIdx<<" End Idx = "<<endIdx<<std::endl;
}
