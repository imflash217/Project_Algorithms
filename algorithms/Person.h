/*
	Solutions to examples, exercises & problems from the book: "C++ Primer, 5th ed."
	copyright @vinaykumar2491 30/10/2017 
*/

// Header file for Sales_data class

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person{
	std::string name;
	std::string address;

	std::string get_name() const { return name};
	std::string get_address() const { return address};
}

std::istream &read(std::istream &is, Person &person){
	is >> person.name >> person.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &person){
	os << person.get_name() << "  " << person.get_address();
	return os;
}



#endif

