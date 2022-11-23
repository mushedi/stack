//stack header file

#ifndef STACK_H
#define STACK_H

#include "data.h"
#include <string>

using std::string;

class Stack {
    
    public:
        //constructor
        Stack();

        //deconstructor
        ~Stack();
        
        //methods
        bool push(int, string);
        bool isEmpty();

        void peek();
        
        Data pop();


    private:
        //instance vars
        int top;
        int size;
        Data **stack;

};


#endif //end STACK_H