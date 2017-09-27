/*


*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

	// reading per word. Starting and ending whitespaces are ignored
	string s1, s2;					// Empty strings
	cin >> s1 >> s2;				// reading first two words separated by 'whitespace' character in a single line
	cout << s1 << s2 << endl;		// printing the read words
	
	// reading a complete line. Starting and ending whitespaces are NOT ignored
	string m_line;
	getline(cin, m_line);
	cout << m_line << endl;
	
	return 0;						// SUCCESS
		
}


