

#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <iostream>
#include <string>

class Window_mgr{

public:
	// location ID for each screen on the Window
	using ScreenIndex = std::vector<Screen>::size_type;		// local type name
	// reset the Screen at the given position to all blanks
	void clear(ScreenIndex);	// function declaration

private:
	std::vector<Screen> screens{Screen(20, 17, "Hi")};

};

// member function definition
void Window_mgr::clear(ScreenIndex i){
	// s is a reference to the screen we have to clear
	Screen &s = screens[i];
	// reset the contents of that screen to all blanks
	s.contents = std::string(s.width * s.height, ' ');	
}


#endif