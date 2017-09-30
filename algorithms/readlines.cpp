/*
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

using std::begin;
using std::end;

int main(){

	// reading per word. Starting and ending whitespaces are ignored
//	string s1, s2;					// Empty strings
//	cin >> s1 >> s2;				// reading first two words separated by 'whitespace' character in a single line
//	cout << s1 << s2 << endl;		// printing the read words
//	
	// reading a complete line. Starting and ending whitespaces are NOT ignored
	string m_line;
	getline(cin, m_line);
	cout << m_line << endl;
	
	//Capitalize the line using iterator
	for(auto iter= m_line.begin(); iter != m_line.end() && !isspace(*iter); ++iter){
		*iter = toupper(*iter);
	}
	cout << m_line << endl;
	
	//----------------------------------------------------------------------------
	const string hexdigits = "0123456789ABCDEF";
	string result;						// holds the hexif'ed string
	string::size_type n;				// Holds the numbers from input
	
	cout << "Enter a series of numbers b/w 0 and 15 "
		 << "separated by SPACES. Hit ENTER when done: "
		 << endl;
	while (cin >> n){					// checks if the input is empty or reached EOF
		if(n < hexdigits.size()){		// checks if the entered integer is in the range [0,15]
			result += hexdigits[n];		// fetches the n'th value from hexdigits string 
		}
	}
	
	cout << result << endl;	
	
	//----------------------------------------------------------------------------
	//  pointers as iterators
	// finding the 1st -ve eleemnt in an array of int
	
	int m_array[10] = {61, 32, 0, 98, -19, -53, 90};
	int *ptr_beg = begin(m_array);
	int *ptr_end = end(m_array);
	
	while(ptr_beg != ptr_end && *ptr_beg >= 0){
		++ptr_beg;
		cout << *ptr_beg << endl;
	}
	
	//----------------------------------------------------------------------------
	// using pointers, write a program to set the elements in an array to 0
	for(int *ptr = begin(m_array); ptr != end(m_array); ++ptr){
		*ptr = 0;
		cout << *ptr << " ";
	}
	cout << endl;
	
	//----------------------------------------------------------------------------
	return 0;						// SUCCESS	
}























