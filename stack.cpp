//stack implementation

#include "stack.h"

//constructor
Stack::Stack(int size){

    top = -1;

    std::smatch m;
    std::regex e("[^0-9$]");
    string s = to_string(size);

    if(size < 2 || !regex_search(s,m,e)){

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

//push Data onto Stack
bool Stack::push(int x, string *info) {

    bool pushed = false;

    if(top < size && x > -1 && *info != ""){
        
        Data *data = new Data;
        
        data->id = x;
        data->information = *info;

        stack[++top] = data;

        pushed = true;
    
    }

    return pushed;
}

//popping Data off top of stack
bool Stack::pop(Data *data){
    bool popped = false;

    if(top != -1) {

        data->id = stack[top]->id;
        data->information = stack[top]->information;

        popped = true;

        delete stack[top--];

    }

    return popped;
}
