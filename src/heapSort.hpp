/*!
 * \file heapSort.hpp
 * \brief 
 * \author tkornut
 * \date Jun 13, 2016
 */

#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

#include <iostream>
#include <math.h>
using namespace std;

void display(int arr[], size_t n) {
	for(size_t i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int arr[], size_t i, size_t j) {
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

void maxHeapify(int arr[], size_t i, size_t n)
{
	// Calculate left-right indices.
    size_t l=2*i+1;
    size_t r=(2*i+2);

	cout << "analysing i=" << i << " l=" << l << " and r=" << r << endl;

    // Find the index of the largest element (root - left -right).
	int index_of_largest = i;

	// Check if index is valid - there is a tree element there.
    if ((l<n) && (arr[l]>arr[i]))
       index_of_largest=l;

    // Check if index is valid - there is a tree element there.
    if ((r<n) && (arr[r]>arr[index_of_largest]))
       index_of_largest=r;

	cout << "largest =" << index_of_largest<< endl;

    if(index_of_largest!=i)
    {
    	// Swap elements.
    	swap (arr, i, index_of_largest);
    	// Heapify this tree node - satisfy the "heap property".
        maxHeapify(arr, index_of_largest, n);
    }//: if
}


void heapSort(int arr[], size_t n) {
	//size of the array
	display(arr, n);

	// Build max heap, starting from the center of the array.
    for(int k = (n/2)-1; k >= 0; k--)
    {
    	// Heapify!
    	maxHeapify(arr, k, n);
    	//display sorted elements
    	//display(arr, n);
    }

    cout << "After max heapify\n";
	//display sorted elements
	display(arr, n);

    // Sort.
    for (size_t i = n-1; i > 0 ; i--)
    {
    	// Swap head with tail - put biggest at the end.
    	swap(arr, i, 0);
    	// Balance tree - heapify!
        maxHeapify(arr, 0, i);
    }

	//display sorted elements
	display(arr, n);

}


#endif /* HEAPSORT_HPP_ */
