#include<iostream>

//Find the min element(pivot)
int findPivot(int arr[], int nsize, int start, int end)
{
    if (arr[start] <= arr[end]) {
	return -1;  //array is not rotated
    }

    while (start <= end) {
	int mid = start + (end - start)/2;
	if (arr[mid] > arr[mid + 1]) {
	    return mid + 1;
	} else if (arr[mid - 1] > arr[mid]) {
	    return mid;
	} else {
	    if (arr[start] <= arr[mid]) {
		start = mid + 1;
	    } else {
		end = mid - 1;
	    }
	}
    }
    return -1;
}

int SearchElementInRotatedSortedArray(int arr[], int nsize, int searchElem)
{
    int PivotIdx = findPivot(arr, nsize, 0, nsize - 1); 
    std::cout<<"Pivot Index = "<<PivotIdx<<std::endl;
    
    int start = 0, end = nsize - 1;

    if (searchElem == arr[PivotIdx])
	return PivotIdx;
    else if (arr[start] <= searchElem) {
	start = 0;
	end = PivotIdx - 1;
    } else {
	start = PivotIdx + 1;
	end = nsize - 1;
    }

    while (start <= end) {
	int mid = start + (end - start)/2;
	if (searchElem == arr[mid]) {
	    return mid;
	} else if (searchElem <= arr[mid]) {
	    end = mid - 1;
	} else {
	    start = mid + 1;
	}
    }
    return -1;
}

int main()
{
    int arr[] = {73, 85, 94, 21, 27, 34, 54, 66};
    int nsize = sizeof(arr)/sizeof(arr[0]);
    int index = SearchElementInRotatedSortedArray(arr, nsize, 27);
    std::cout<<"Element 27 found at index: "<<index<<std::endl;

    int index1 = SearchElementInRotatedSortedArray(arr, nsize, 73);
    std::cout<<"Element 73 found at index: "<<index1<<std::endl;

    int index2 = SearchElementInRotatedSortedArray(arr, nsize, 54);
    std::cout<<"Element 54 found at index: "<<index2<<std::endl;

    int index3 = SearchElementInRotatedSortedArray(arr, nsize, 100);
    std::cout<<"Element 100 found at index: "<<index3<<std::endl;
}
