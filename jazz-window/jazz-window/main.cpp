//
//  main.cpp
//  jazz-window
//
//  Created by vinfinit on 3/25/19.
//  Copyright © 2019 vinfinit. All rights reserved.
//

#include <iostream>

class window {};

class window_with_toolbar: public window {};

class window_with_menu: public window {};

class window_with_menu_and_toolbar:
public window_with_menu,
public window_with_toolbar {};

/*
 Problems:
 1) if something changes in window interface all objects receive the update and it can break them
 2) multiple inheritance (property duplication and etc.)
 3) if you want to add some more features for example window_with_statusbar you need to create a lot of extra classes with different combinations
 
 Possible solutions:
 1) Decorator pattern https://en.wikipedia.org/wiki/Decorator_pattern
 2) Composite pattern https://en.wikipedia.org/wiki/Composite_pattern
 */


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
