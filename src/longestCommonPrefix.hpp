/*!
 * \file longestCommonPrefix.hpp
 * \brief 
 * \author tkornut
 * \date Jun 12, 2016
 */

#ifndef LONGESTCOMMONPREFIX_HPP_
#define LONGESTCOMMONPREFIX_HPP_

#include <string>
#include <vector>

#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

string longestCommonPrefix(string & names_) {
	// Check whether there is something to parse;)
	if (names_.size() == 0)
		return "";

	std::istringstream ss(names_);
	std::string name;
	vector<string> names;

	// Split vector.
	while(std::getline(ss, name, ',')) {
	    std::cout << name << '\n';
	    names.push_back(name);
	}

	// Special case - there is one name only.
	if (names.size() == 1)
		return names[0];

	// Find smallest string length.
	size_t smallest_length = std::numeric_limits<size_t>::max();
	for (auto name: names) {
		if (name.size() < smallest_length)
			smallest_length = name.size();
	}//: for
	cout << "smallest_length=" << smallest_length << endl;

	// Check the smallest length.
	if (smallest_length == 0)
		return "";

	// Iterate and compare consecutive elements of names.
	string prefix = "";
	for (size_t i=0; i< smallest_length; i++) {
		char ref_letter = names[0][i];
		bool add_letter = true;
		for (size_t n=1; n < names.size(); n++ ) {
			// Check whether this is the same letter.
			if (names[n][i] != ref_letter) {
				add_letter = false;
				break;
			}//: if
		}//: for all names
		if (add_letter) {
			prefix += ref_letter;
		}
	}//: for "all" letters

	return prefix;
}



#endif /* LONGESTCOMMONPREFIX_HPP_ */
