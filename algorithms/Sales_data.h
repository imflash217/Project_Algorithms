/*
	Solutions to examples, exercises & problems from the book: "C++ Primer, 5th ed."
	copyright @vinaykumar2491 27/09/2017 
*/

// Header file for Sales_data class

#ifndef SALES_DATA_H
	#define SALES_DATA_H
	#include <string>
	
	struct Sales_data{

		//new member functions, operations on Sales_data objects
		std::string isbn() const {return bookNo};	// declaration and definition
		Sales_data& combine(const Sales_data&);		// declaration
		double avg_price() const;					// declaration

		// data members
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;	
	};

	// non-member Sales_data inteface functions
	Sales_data add(const Sales_data&, const Sales_data&);
	std::ostream &print(std::ostream&, const Sales_data&);
	std::istream &read(std::istream&, Sales_data&);

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
	

#endif




