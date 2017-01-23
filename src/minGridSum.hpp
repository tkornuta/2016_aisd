/*!
 * \file minGridSum.hpp
 * \brief 
 * \author tkornut
 * \date Jun 12, 2016
 */

#ifndef MINGRIDSUM_HPP_
#define MINGRIDSUM_HPP_

#include <string>
#include <vector>

template <size_t rows, size_t cols>
long minGridSum(int costs_[rows][cols]){
	// Check whether grid is proper.
	if ((rows  == 0) || (rows == 0))
		return -1;

	// Display the matrix.
	cout << "Cost grid\n";
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			cout << costs_[y][x] << " ";
		}//: for x
		cout << endl;
	}//: for y

	// Check special cases: width || height =1.
	if (rows == 1) {
		long sum = 0;
		for (size_t x=0; x<cols; x++)
			sum +=costs_[0][x];
		return sum;
	}//: if

	if (cols == 1) {
		long sum = 0;
		for (size_t y=0; y<rows; y++)
			sum +=costs_[y][0];
		return sum;
	}//: if

	// Solve normal case.

	// Create/fill cost matrix.
	int total_cost[rows][cols];
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			total_cost[y][x] = std::numeric_limits<int>::max();
		}//: for x
	}//: for y

	// Assign the "initial" cost -associated with start node (0,0).
	total_cost[0][0] = costs_[0][0];

	// Actions - pairs of <dy,dx>.
	std::vector<std::pair<short,short> > actions;
	actions.push_back(make_pair(-1,0)); // N
	actions.push_back(make_pair(0,1)); // E
	actions.push_back(make_pair(1,0)); // S
	actions.push_back(make_pair(0,-1)); // W

	// Update table while there is any change in total cost table.
	bool change = true;
	while (change) {
		change = false;

		// Iterate through all grid cells.
		for (size_t y=0; y<rows; y++) {
			for (size_t x=0; x<cols; x++) {
				// Check whether we already have found a path to get there.
				if (total_cost[y][x] == std::numeric_limits<int>::max())
					continue;
				// ok, so check where we can get from that place.
				for(const auto & a: actions) {
					// "New" coordinates.
					size_t ny = y + a.first;
					size_t nx = x + a.second;
					// Check whether coordinates are valid.
					if ((nx >= cols) || (ny >= rows))
						continue;
					// Else - try to assign "smaller" cost.
					if (total_cost[ny][nx] > (costs_[ny][nx] + total_cost[y][x])) {
						total_cost[ny][nx] = (costs_[ny][nx] + total_cost[y][x]);
						change = true;
					}//: if
				}//: for a
			}//: for x
		}//: for y


	}//: while

	// Display total cost table.
	cout << "Total cost grid\n";
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			cout << total_cost[y][x] << " ";
		}//: for x
		cout << endl;
	}//: for y


	return total_cost[rows-1][cols-1];
}



#endif /* MINGRIDSUM_HPP_ */
