

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <cstddef>

class Screen{

// Window_mgr is a 'friend' of Screen; so Window_mgr can access 'private' members of Screen
friend class Window_mgr;

public: 
	typedef std::string::size_type pos;		// a "type member"
	// using pos = std::string::size_type;		// OK. Alternative way of type member declaration
	Screen() = default;			// default constructor
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c){}
	char get() const { return contents[cursor]; }		// implicitly inline
	inline char get(pos ht, pos wd) const;				// explicitly inline
	Screen &move(pos r, pos c);							// can be made inline later

	void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_ctr;		// may be changed even in a 'const' object
}

// declared as 'inline' in the function DECLARATION inside the class
char get(pos r, pos c) const {
	pos row = r * width;			// compute new row 
	return contents[row + c];		// return character at a given column
}

// explicitly declaring 'inline' in the function DEFINITION
inline Screen &Screen::move(pos r, pos c){
	pos row = r * width;			// compute the row location
	cursor = row + c;				// move cursor to the column within that row
	return *this;					// return this object as an 'lvalue'
}

void Screen::some_member() const {
	++access_ctr;
}

#endif