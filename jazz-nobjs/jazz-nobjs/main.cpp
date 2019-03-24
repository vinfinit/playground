//
//  main.cpp
//  jazz-nobjs
//
//  Created by vinfinit on 3/25/19.
//  Copyright © 2019 vinfinit. All rights reserved.
//

#include <iostream>

template <typename T>
struct counter
{
    counter()
    {
        objects_created++;
        objects_alive++;
    }
    
    virtual ~counter()
    {
        --objects_alive;
    }
    static int objects_created;
    static int objects_alive;
};
template <typename T> int counter<T>::objects_created( 0 );
template <typename T> int counter<T>::objects_alive( 0 );

class X : counter<X>
{};

class Y : counter<Y>
{};


int main(int argc, const char * argv[]) {
    X x1;
    
    {
        X x2;
        X x3;
        X x4;
        X x5;
        Y y1;
        Y y2;
    }
    
    Y y3;
    
    std::cout << "created: "
    << " X:" << counter<X>::objects_created
    << " Y:" << counter<Y>::objects_created
    << std::endl;
    
    std::cout << "alive: "
    << " X:" << counter<X>::objects_alive
    << " Y:" << counter<Y>::objects_alive
    << std::endl;
}
