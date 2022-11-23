#include "stack.h"

//constructor
Stack::Stack(int x){
    
    top = -1;

    size = x;
    
    std::smatch m;
    std::regex e ("[^0-9$]");
    string s = std::to_string(size);

    if (size < 2 || !regex_search(s,m,e)) {
        size = DEFAULT;
    }

    stack = new Data*[size];
}

//deconstructor
Stack::~Stack(){
    
    for(int i = top; i > -1; i--){
        
        delete stack[i];
    
    }

    delete[] stack;

}

//push Data struct onto stack method
bool Stack::push(int x, string *info) {

    bool pushed = false;
    
    if(top < size && x > -1 && *info != "") {

        Data *data = new Data;

        data->id = x;
        data->information = *info;

        stack[++top] = data;

        pushed = true;

    }

    return pushed;

}


//popping Data struct off top of stack if stack is not empty
bool Stack::pop(Data *data){

    bool popped = false;

    if( top != -1) {

        data->id = stack[top]->id;
        data->information = stack[top]->information;

        popped = true;

        delete stack[top--];
        
    } else {

        data->id = -1;
        data->information = "";

    }

    return popped;
}


//peeking top of stack
bool Stack::peek(Data *data){

    bool peeked = false;

    if( top != -1) {

        data->id = stack[top]->id;
        data->information = stack[top]->information;

        peeked = true;
        
    } else {

        data->id = -1;
        data->information = "";

    }

    return peeked;
}


//isEmpty checks if stack is empty
bool Stack::isEmpty(){

    return top == -1;
}


