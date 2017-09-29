#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
	
	vector<int> m_sortedIntVector{1, 3, 12, 14, 17, 19, 21, 30, 33, 34, 45, 56};		// sorted int vector
	int m_soughtValue;				// the value we are searching for in the sorted vector
	
	cout << "Please enter a integer!" << endl;
	cout << ">> ";
	cin >> m_soughtValue;	// taking input from the user

	// beg & end will denote the range we are searching in 
	auto beg = m_sortedIntVector.begin();
	auto end = m_sortedIntVector.end();
	auto mid = beg + (end-beg)/2;				// The middle of the part-of-vector we are searching
	
	// while there are still elements to look for, we havn't found the sought value (m_soughtValue)
	while(mid != end && *mid != m_soughtValue){
		cout << "*mid = " << *mid << endl;
		
		if(m_soughtValue < *mid){
			end = mid;
		}else{
			beg = mid + 1;
		}
		
		mid = beg + (end-beg)/2;		// new mid point
	}
	
	if (m_soughtValue == *mid){
		cout << "We found it. And the value is: " << *mid << endl;
	}else{
		cout << "SORRY, the value you are trying to find isn't in the vector." << endl;
	}
	
	return 0;		// SUCCESS
}















