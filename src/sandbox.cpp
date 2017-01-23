//============================================================================
// Name        : sandbox.cpp
// Author      : tkornut
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//#include "findUniqueSubstring.hpp"
//#include "longestCommonPrefix.hpp"
//#include "minGridSum.hpp"
//#include "uniquePathsGrid.hpp"
//#include "uniquePathsObstacleGrid.hpp"
//#include "medianTwoSortedArrays.hpp"
//#include "heapSort.hpp"
#include "mergeTwoSortedLists.hpp"

int main() {

/*	// Test string.
	string test = "abcbbbbcccedbbbbbdddadacb";
	string sub = findUniqueSubstring(test, 2);
	cout << "found substring: " << sub << endl;*/

/*	string names = "btom,atata,atablet";
	string prefix = longestCommonPrefix(names);
	cout << "found prefix: " << prefix << endl;*/

/*	// Rowmajor! (matrix rows x cols)
	int grid[4][3] = {0,4,2,1,1,1,6,7,8,9,10,11};
	long sum = minGridSum<4,3>(grid);
	cout << "sum = " << sum << endl;*/

/*	long paths = uniquePathsGrid(3,4);
	cout<< "number of unique paths = " << paths << endl;*/

/*	bool obstacles[3][4] = {0,0,0,0,0,1,0,0,0,0,0,0};
	long paths = uniquePathsObstacleGrid<3,4>(obstacles);
	cout<< "number of unique paths = " << paths << endl;*/

/*	int a[4] = {1,3,5,7};
	int b[4] = {4,6,8,9};
	int median = medianTwoSortedArrays(a,0, 3, b, 0, 2);
	cout << "median = " << median << endl;*/

/*	int arr[] = {10, 5, 3, 4, 8, 9, 2, 11, 6, 7, 1};
	heapSort(arr, 11);*/

	int a[4] = {1,3,5,7};
	int b[4] = {4,6,8,9};
	int c[8];
	mergeTwoSortedLists(a,4,b,4,c);

/*	std::vector<int> myvector;
	for (int i=0; i<9; i++) myvector.push_back(i);
	myvector.erase (myvector.begin());
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';*/

	return 0;
}
