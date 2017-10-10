/*
	Exercise 6.10 || @vinaykumar2491
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void swap(int *arg1, int *arg2){

	cout << "Original locations are: " << arg1 << ", " << arg2 << endl;
	cout << "*arg1 = " << *arg1 << ", *arg2 = " << *arg2 << endl;
	int *temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;

	cout << "Swapped locations are: " << arg1 << ", " << arg2 << endl;	
	cout << "*arg1 = " << *arg1 << ", *arg2 = " << *arg2 << endl;
}

// compare the length of two strings
bool isShorter(const string &arg1, const string &arg2){
	return (arg1.size() < arg2.size());
}


// finding the 1st occurance of a char in a given string and no of times it has occured

string::size_type find_char(const string &arg1, const char &arg2, string::size_type &arg3){
	auto first_occurance = arg1.size();		// setting the default value of 1st occurance of the key 

	for(decltype(first_occurance) i = 0; i != arg1.size(); ++i){
		if(arg1[i] == arg2){
			if(first_occurance == arg1.size()){
				first_occurance = i;
			}
			++arg3;
		}
	}

	return first_occurance;
}



int main(){

	// swapping two ints by swapping the addresses of the two pointers to them
	int i = 0, j = 1;
	swap(&i, &j);
	
	// finding a char in a string
	string str = ("Rustom Potter");
	char chr = 't';
	string::size_type frequency = 0;
	auto index = find_char(str, chr, frequency);
	cout << "index = " << index << ", frequency = " << frequency << endl;

	//
	return 0;		// SUCCESS
}

