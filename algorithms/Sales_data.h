/*
	Solutions to examples, exercises & problems from the book: "C++ Primer, 5th ed."
	copyright @vinaykumar2491 27/09/2017 
*/

// Header file for Sales_data class

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data{

// 'friend' declarations for non-member Sales_data 
friend Sales_data &read(std::istream&, Sales_data&);
friend Sales_data &print(std::ostream&, const Sales_data&);
friend Sales_data &add(const Sales_data&, const Sales_data&);

public:		// added access specifiers
	// Constructors
	Sales_data() = default;
	Sales_data(const std::string &str): bookNo(str){}
	Sales_data(const std::string &str, unsigned n, double p): 
		bookNo(str), units_sold(n), revenue(n*p){}
	Sales_data(std::istream &is){
		read(is, *this);
	}

	//member functions, operations on Sales_data objects
	std::string isbn() const {return bookNo;}	// declaration and definition
	Sales_data& combine(const Sales_data&);		// declaration

private:		// added access specifiers	
	double avg_price() const{
		if(units_sold){
			return revenue/units_sold;
		}else{
			return 0;
		}
	}					// declaration & definition

	// data members
	std::string bookNo;				// no in-class initializer, will be default-initialized (if no constructor)
	unsigned units_sold = 0;		// in-class initializer for units_sold
	double revenue = 0.0;			// in-class initializer for revenue
};

// MEMBER function definitions
/*
Sales_data::Sales_data(std::istream &is){
	read(is, *this);
}
*/
/*
double Sales_data::avg_price() const{
	if(units_sold){
		return revenue/units_sold;
	}else{
		return 0;
	}
}
*/

Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;	// return the object on which the combine function is called
}

// NON-MEMBER FUNCTIONS definitions of Sales_data interface
// These functions are part of the Sales_data interface but not memebers of the class,
// so they will not Compile if we use 'class' instead of 'struct'. 
// To compile these we need to declare these as 'friend' in the class definition

// Declarations of these non-member functions are done in Sales_data.h header file

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




