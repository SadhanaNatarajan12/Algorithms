#include<iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void segregate_0_1_2(int arr[], int nsize)
{
    int low = 0, mid = 0, high = nsize - 1;
    while (mid <= high) {
	switch (arr[mid]) {
	    case 0:
		swap(arr[low], arr[mid]);
		low++;
		mid++;
		break;
	    case 1:
		mid++;
		break;
	    case 2:
		swap(arr[mid], arr[high]);
		high--;
		break;
	}
    }
}

void segregatenumbers(int arr[], int nsize, int pivot)
{
    int low = 0, mid = 0, high = nsize - 1;
    while (mid <= high) {
	if (arr[mid] < pivot) {
	    swap(arr[low], arr[mid]);
	    low++;
	    mid++;
	} else if (arr[mid] == pivot) {
	    mid++;
	} else {
	    swap(arr[mid], arr[high]);
	    high--;
	}
    }
}

int main()
{
    std::cout<<"Segregate 0's, 1's and 2's"<<std::endl;
    int arr[] = {0, 2, 1, 0, 2, 1, 1, 2, 0, 1, 2, 2};
    int nsize = sizeof(arr)/sizeof(arr[0]);

    segregate_0_1_2(arr, nsize);
    for (int i = 0; i < nsize; i++) {
	std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Segregate numbers given the pivot"<<std::endl;

    int arr1[] = {0, 2, 1, 0, 2, 1, 1, 2, 0, 1, 2, 2};
    int nsize1 = sizeof(arr1)/sizeof(arr1[0]);
    int pivot = 1;

    segregatenumbers(arr1, nsize1, pivot);
    for (int i = 0; i < nsize1; i++) {
	std::cout<<arr1[i]<<" ";
    }
    std::cout<<std::endl;
}
