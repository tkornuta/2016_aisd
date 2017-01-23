/*!
 * \file uniquePathsGrid.hpp
 * \brief 
 * \author tkornut
 * \date Jun 12, 2016
 */

#ifndef UNIQUEPATHSGRID_HPP_
#define UNIQUEPATHSGRID_HPP_

template <size_t rows, size_t cols>
long uniquePathsObstacleGrid(bool obstacles_[rows][cols]) {
	// Check "grid" dimensions.
	if ((rows == 0) || (cols == 0))
		return -1;

	// Display the matrix.
	cout << "Obstacles:\n";
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			cout << obstacles_[y][x] << " ";
		}//: for x
		cout << endl;
	}//: for y

	// Create/fill cost matrix.
	int paths[rows][cols];
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			paths[y][x] = 0;
		}//: for x
	}//: for y

	// Ok, so now start to "unroll" the possible actions.
	// Unroll "right only" - this is the only way we can get to the cells in top row + start cell.
	for (size_t x=0; x<cols; x++) {
		// If this is an obstacle - the path is closed.
		if (obstacles_[0][x])
			break;
		paths[0][x] = 1;
	}//: for x

	// Unroll "down only" - this is the only way we can get to the cells in left column.
	for (size_t y=1; y<cols; y++) {
		// If this is an obstacle - the path is closed.
		if (obstacles_[y][0])
			break;
		paths[y][0] = 1;
	}//: for x

	// Unroll the other cells - sum paths from top and right leading to that cell
	for (size_t y=1; y<rows; y++) {
		for (size_t x=1; x<cols; x++) {
			// Check if obstacle.
			if (obstacles_[y][x])
				continue;
			// Otherwise - sum paths.
			paths[y][x] = paths[y-1][x] + paths[y][x-1];
		}//: for x
	}//: for y


	// Display the matrix.
	cout << "Paths:\n";
	for (size_t y=0; y<rows; y++) {
		for (size_t x=0; x<cols; x++) {
			cout << paths[y][x] << " ";
		}//: for x
		cout << endl;
	}//: for y

	return 0;
}



#endif /* UNIQUEPATHSGRID_HPP_ */
