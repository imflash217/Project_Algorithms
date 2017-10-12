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


// functions that take array as arguments

// method 1: using a marker
void print_func1(const char *arg1){
	if(arg1){						// if arg1 is not a NULL pointer
		while(*arg1){				// as long as char it points to is not a NULL value
			cout << *arg1++;		// prints the char and increment the pointer
		}
	}
}

// Method 2: using the standard library conventions
void print_func2(const int *beg, const int *end){
	while(beg != end){
		cout << *beg++;
	}
}

// Method 3: Explicitly passing the size parameter
void print_func3(const int intArray[], string::size_type arraySize){
	for(string::size_type i = 0; i != arraySize; ++i){
		cout << intArray[i] << endl;
	}
}

// we can assign to the result of a function that returns a "reference to non-const"
char &get_val(string &str, string::size_type ix){
	return str[ix];
}

// if the return type is a reference-to-const; we can't assign to the result of the func. call
const string &shorterString(const string &str1, const string &str2){
	return (str1.size() < str2.size()) ? str1 : str2;		// conditional operator
}


//------------------------------------------------------------------------------------------

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

	// assigning to the return of a function
	get_val(str, 6) = '_';		// we can assign to the result of a function that returns a "reference to non-const" lvalue
	cout << str << endl;		// prints the updated str

	//
	string str1 = ("Rustom");
	string str2 = ("Potter");
	cout << shorterString(str1, str2) << endl;
	// shorterString(str1, str2) = "Prithvi";		// cannot assign to a const lvalue returned by shorterString()
	// cout << str2 << endl;

	//
	return 0;		// SUCCESS
}

