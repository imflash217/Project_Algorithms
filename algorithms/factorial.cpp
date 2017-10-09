/*
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long factorial(int val){
	
	long temp_fact = 1;
	while(val > 1){
		temp_fact *= val--;		// assign (temp_fact * val) to temp_fact and then decrement val

		cout << "temp_fact = " << temp_fact << " = " << temp_fact << " * " << val << endl;
	}

	return temp_fact;
}


int main(){
	
	cout << "Enter the integer for which you want to find the factorial." << endl;
	int value;
	cin >> value;
	
	long fact_val = factorial(value);
	cout << "The factorial for the entered integer is : " << fact_val << endl;

	return 0;		// SUCCESS
}