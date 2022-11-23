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
