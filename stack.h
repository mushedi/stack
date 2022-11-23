//stack header file

#ifndef STACK_H
#define STACK_H

#define SIZE 10


class Stack {
    
    public:
        //constructor
        Stack();

        //deconstructor
        ~Stack();
        
        //methods
        bool push(int);
        bool isEmpty();

        int peek();
        int pop();


    private:
        //instance vars
        int top;
        int stack[SIZE];

};


#endif //end STACK_H