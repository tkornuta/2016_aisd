/*!
 * \file medianTwoSortedArrays.hpp
 * \brief 
 * \author tkornut
 * \date Jun 12, 2016
 */

#ifndef MEDIANTWOSORTEDARRAYS_HPP_
#define MEDIANTWOSORTEDARRAYS_HPP_

#include <limits>

int medianTwoSortedArrays(int* a, size_t a_start, size_t a_end, int* b, size_t b_start, size_t b_end) {
	cout << "a = ";
	for(size_t i = a_start; i <= a_end; i++)
		cout<< a[i] << " ";
	cout << endl;
	cout << "b = ";
	for(size_t i = b_start; i <= b_end; i++)
		cout<< b[i] << " ";
	cout << endl;


	// Calculate lengths.
	size_t a_len = a_end - a_start +1;
	size_t b_len = b_end - b_start +1;
	// Calculate medians.
	size_t a_med = a_start + a_len/2;
	size_t b_med = b_start + b_len/2;

	cout << "a[a_len/2] = " << a[a_med] << endl;
	cout << "b[b_len/2] = " << b[b_med] << endl;

	// Handle special cases.
	if ((a_len <= 0) && (b_len <= 0))
		return std::numeric_limits<int>::infinity(); // ERROR

	// Check
	if ((a_len == 1) && (b_len == 1))
		return b[b_med];
	if (b_len <= 1)
		return a[a_med];


	// Ok, so not do the magic.
	// Check medians and recursively search in the subsets.

	if (a[a_med] <= b[b_med]) {
		cout << "a[a_med] <= b[b_med]\n";
		return medianTwoSortedArrays(a, a_med, a_end, b, b_start, b_med );
	} else {
		return medianTwoSortedArrays(a, a_start, a_med, b, b_med, b_end );
	}

	return 0;
}


#endif /* MEDIANTWOSORTEDARRAYS_HPP_ */
