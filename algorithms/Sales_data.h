/*
	Solutions to examples, exercises & problems from the book: "C++ Primer, 5th ed."
	copyright @vinaykumar2491 27/09/2017 
*/

// Header file for Sales_data class

#ifndef SALES_DATA_H
#define SALES_DATA_H
	
#include <string>
#include <iostream>
	
struct Sales_data{

	//member functions, operations on Sales_data objects
	std::string isbn() const {return bookNo};	// declaration and definition
	Sales_data& combine(const Sales_data&);		// declaration
	double avg_price() const;					// declaration

	// data members
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;	
};

// function definitions
double Sales_data::avg_price() const{
	if(units_sold){
		return revenue/units_sold;
	}else{
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;	// return the object on which the combine function is called
}

// non-member function definitions of Sales_data interface
// declarations of these non-member functions are done in Sales_data.h header file

// NOTE: reading/writing to a stream changes the stream, so both the functions below take 
// ordinary references not references to 'const' for stream
std::istream &read(std::istream &is, Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item){
	os << item.isbn() << "   " << item.units_sold << "   "
		<< item.revenue << "   " << item.avg_price();
	return os;
}

// add function takes two Sales_data object, combine them and return a new Sales_data object

Sales_data &add(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;	// copy data members from lhs into sum
	lhs.combine(rhs);		// add data members from rhs to lhs
	return sum;
}
	
#endif




