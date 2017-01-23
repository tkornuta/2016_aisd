/*!
 * \file mergeTwoSortedLists.hpp
 * \brief 
 * \author tkornut
 * \date Jun 14, 2016
 */

#ifndef MERGETWOSORTEDLISTS_HPP_
#define MERGETWOSORTEDLISTS_HPP_



void mergeTwoSortedLists(int A[], int m, int B[], int n, int C[]) {
	size_t c_size = m+n;

	// Print the inputs.
	for (size_t i=0; i<m; i++)
		cout << A[i] << " ";
	cout << endl;
	for (size_t i=0; i<n; i++)
		cout << B[i] << " ";
	cout << endl;

	for (size_t i=0; i<(m+n); i++)
		C[i] = 0;
	for (size_t i=0; i<(m+n); i++)
		cout << C[i] << " ";
	cout << endl;

	// While two indices are > 0 - merge elements manually.
	while ((m > 0) && (n > 0)){
		cout << "m=" << m << " n=" << n <<endl;
		if(A[m-1] > B[n-1]){
			C[m+n-1] = A[m-1];
			m--;
		}else{
			C[m+n-1] = B[n-1];
			n--;
		}
	}//: while

	// Copy the remaining part - from B...
	while(n > 0){
		C[m+n-1] = B[n-1];
		n--;
	}
	// ... OR from A
	while(m > 0){
		C[m+n-1] = A[m-1];
		m--;
	}

	// Print the results.
	for (size_t i=0; i<c_size; i++)
		cout << C[i] << " ";
	cout << endl;
}

#endif /* MERGETWOSORTEDLISTS_HPP_ */
