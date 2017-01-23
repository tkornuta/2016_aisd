/*!
 * \file UniqueString.hpp
 * \brief 
 * \author tkornut
 * \date Jun 12, 2016
 */

#ifndef FINDUNIQUESUBSTRING_HPP_
#define FINDUNIQUESUBSTRING_HPP_

#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

/*!
 * \brief Class Represents the
 * \author tkornuta
 */
class UniqueSubstring {
public:

	/// Default constructor.
	UniqueSubstring(size_t chars_limit_) : chars_limit(chars_limit_) {
		start = -1;
		final = -2;
	}

	/// Returns the length of the unique string.
	size_t size() {
		return final - start + 1;
	}

	/// Checks whether character is present in given substring.
	bool contains(char c){
		for (size_t i=0; i<chars.size(); i++) {
			if (chars[i] == c)
				return true;
		}//: for
		// If wasn't found.
		return false;
	}

	/// Updates index of a given character in substring.
	void update(char c_, size_t i_){
		size_t index =-1;
		// Find the index of the character.
		for (size_t i=0; i<chars.size(); i++) {
			if (chars[i] == c_) {
				index = i;
			}//: if
		}//: for

		// Set the new "last" index.
		last[index] = i_;
		final = i_;
	}

	bool canAdd() {
		//cout << "chars.size()= " << chars.size() << " chars_limit=" << chars_limit <<endl;
		return chars.size() < chars_limit;
	}


	/// add character to substring, update the "last index".
	void add(char c_, size_t i_) {
		chars.push_back(c_);
		first.push_back(i_);
		last.push_back(i_);
		final = i_;
		if (start < 0)
			start = i_;
	}

	// Copies data from one substring to another.
	UniqueSubstring & operator = (const UniqueSubstring & us_) {
		// Copy data.
		this->chars = us_.chars;
		this->first =  us_.first;
		this->last =  us_.last;

		this->start =  us_.start;
		this->final =  us_.final;

		return *this;
	}

	void removeFirst (string s_){
		size_t smallest = std::numeric_limits<size_t>::max();
		size_t index;
		// Find the "smallest last" index.
		for (size_t i=0; i<chars.size(); i++) {
			if (last[i] < smallest) {
				smallest = last[i];
				index= i;
			}//: if
		}//: for
		//cout << "index: " << index << " associated with last[i]: " << smallest << endl;
		// Remove that letter from our substring.
		chars.erase(chars.begin() + index);
		first.erase(first.begin() + index);
		last.erase(last.begin() + index);

/*		cout << "after removal: chars ";
		for (size_t i=0; i<chars.size(); i++)
			cout << chars[i] << " ";
		cout << endl;
		cout << "after removal: first ";
		for (size_t i=0; i<first.size(); i++)
			cout << first[i] << " ";
		cout << endl;
		cout << "after removal: last ";
		for (size_t i=0; i<last.size(); i++)
			cout << last[i] << " ";
		cout << endl;*/

		// Special case: 0 elements.
		if (chars.size() == 0) {
			start = final = -1;
		}

		// Recalculate the "start" substring.
		start = final;
		for (size_t i = final-1; i>0; i--) {
			if (!contains(s_[i]))
				break;
			start = i;
		}//: for

		//cout << "start:" <<start << " final: " << final << endl;
	}

/*	friend ostream & operator<<(ostream &os_, const UniqueSubstring & us_) {
		return os_;
	    //return os_ << p.to_str();
	}*/

	string returnSubstr (string s_) {
		if (start < 0)
			return "-";
		else
			return s_.substr(start, (final-start)+1);
	}

private:
	/// Indices of first appearance of characters constituting the encoded substring.
	std::vector<size_t> first;
	/// Indices of last appearance of characters constituting the encoded substring.
	std::vector<size_t> last;
	/// Index of the first element.
	long start;
	/// Index of the last element.
	long final;
	/// Characters used in a given substring.
	std::vector<char> chars;

	const size_t chars_limit;
};


std::string findUniqueSubstring(string test_, size_t max_length_) {
	cout<< "string: "<< test_ <<endl;

	if (test_.size() == 0)
		return "";
	//cout<< "substring: "<< test.substr(1,2)<<endl;

	// Variables storing best and currently analyzed substring.
	UniqueSubstring best(max_length_), tmp(max_length_);

	for(size_t i=0; i < test_.size(); i++ ) {
		cout <<  "letter: " << test_[i]  << endl;

		// Check whether the analyzed char is in the list.
		if (tmp.contains(test_[i])) {
			//cout <<"case 1\n";
			// If so, update the idex of given char.
			tmp.update (test_[i], i);
			// If not, check two cases.
			// First - check if we can add character to existing substring.
		} else if (tmp.canAdd()) {
			//cout <<"case 2\n";
			tmp.add(test_[i], i);
		} else {
			//cout <<"case 3\n";
			// "Close" the current substring, start new one.
			if(tmp.size() > best.size()) {
				best = tmp;
			}//: if
			// Start new substring, use data from previous substring.
			tmp.removeFirst(test_);
			//cout << "tmp after remove: " << tmp.returnSubstr(test) <<endl;
			tmp.add(test_[i], i);
			//cout << "tmp after remove + add: " << tmp.returnSubstr(test) <<endl;
		}//: else

		cout << "tmp: " << tmp.returnSubstr(test_) <<endl;
		cout << "best: " << best.returnSubstr(test_) <<endl;

	}//: for
	if(tmp.size() > best.size()) {
		best = tmp;
	}//: if
	return best.returnSubstr(test_);

}



#endif /* FINDUNIQUESUBSTRING_HPP_ */
