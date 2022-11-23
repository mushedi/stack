//stack implementation

#include "stack.h"

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