#ifndef NUM_H
#define NUM_H


#include <iostream>
#include <string>


class Num {
public:
// Pure virtual function for polymorphism
    virtual string getKill() const = 0; 
    virtual ~Num() = default;
};



#endif 