/* Delete the repeated elements in a sorted array in O(n) time and O(1) space !!!
 * Example: Given an input array  {2, 3, 5, 5, 7, 11, 11, 11, 13}
 * Expected output		  {2, 3, 5, 7, 11, 13, 0,  0,  0}
 */

//Returns the number of valid entries after deletion or in other words returns the number of non duplicate elements!

#include <iostream>

//O(n) time and O(n) space
int deleteDuplicates(int arr[], int nsize)
{
    if (nsize == 0 || nsize == 1) {
	return nsize;
    }

    int temp[nsize];

    int j = 0;
    for (int i = 0; i < nsize - 1; i++) {
	if (arr[i] != arr[i+1]) {
	    temp[j] = arr[i];
	    j++;
	}
    }
    //Copy the last element, as it is never copied irrespective of whether it is duplicate or not!
    temp[j] = arr[nsize - 1];

    
    for (int i = 0; i <= j; i++) { //Copying back to original array!!!
	arr[i] = temp[i];
    }

    return j+1;	//returning number of non duplicate elements.
}

//O(n) time and O(1) space
//Same as previous, but just maintaining an extra index, instead of allocating a new temp array! 
int deleteDuplicates_constantspace(int arr[], int nsize)
{
    if (nsize == 0 || nsize == 1) {
	return nsize;
    }

    int j = 0;
    for (int i = 0; i < nsize - 1; i++) {
	if (arr[i] != arr[i+1]) {
	    arr[j] = arr[i];
	    j++;
	}
    }
    //Copy the last element, as it is never copied irrespective of whether it is duplicate or not!
    arr[j] = arr[nsize - 1];
    
    return j + 1; //returning the number of non duplicate elements.
}

int main()
{
    int arr[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    int nsize = sizeof(arr) / sizeof(arr[0]);
    nsize = deleteDuplicates(arr, nsize);

    std::cout<<"Array after deleting the duplicates!!!"<<std::endl;
    for (int i = 0; i <= nsize - 1; i++) {
	std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    int arr1[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    int nsize1 = sizeof(arr1) / sizeof(arr1[0]);
    nsize1 = deleteDuplicates_constantspace(arr1, nsize1);


    std::cout<<"Array after deleting the duplicates using constant space!!!"<<std::endl;
    for (int i = 0; i <= nsize1 - 1; i++) {
	std::cout<<arr1[i]<<" ";
    }
    std::cout<<std::endl;
}
