//stack header file

#ifndef STACK_H
#define STACK_H

#define DEFAULT 10

#include "data.h"
#include <string>
#include <regex>

using std::string;
using std::to_string;
using std::regex_search;

class Stack {
    
    public:
        //constructor
        Stack(int);

        //deconstructor
        ~Stack();
        
        //methods
        bool push(int, string*);
        bool peek(Data*);
        bool pop(Data*);
        bool isEmpty();


    private:
        //instance vars
        int top;
        int size;
        Data **stack;

};


#endif //end STACK_H