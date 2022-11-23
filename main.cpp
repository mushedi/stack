#include "main.h"

int main(int argc, char **argv) {

    srand(time(NULL));

    std::smatch m;
    std::regex e ("[^0-9$]");
    string s;

    if(argc == 2) {
        s = argv[1];
    }

    if(argc == 2 && !regex_search(s, m, e)) {

        Data *data = new Data;
        string *str = new string;
        int size = atoi(argv[1]) < 2 ? 10 : atoi(argv[1]);
        Stack stack(size);
        

        cout << "Beginning Testing...\n\n";

        // TESTS FOR WHEN STACK IS EMPTY LINES 25-73

        cout << "TESTING EMPTY OPERATIONS\n-------------------------------\n";

        if(stack.isEmpty()){

            //expected answer
            cout << "Stack is empty\n\n";

        } else {
            
            cout << "Stack is NOT empty.\n\n";
        }

        if(stack.peek(data)){

            cout << "Peek Successful.\n" << "id: " << data->id << "\ninformation: " << data->information << endl << endl;
        
        } else {
            
            //expected answer
            cout << "Peek Failed, underflow error, stack is empty\n";
            cout << "expected id value: -1 \n" << "recieved id value: " << data->id;
            cout << "\nexpected information value: " << "\nrecieved information value: " << data->information << endl << endl;
        }

        if(stack.pop(data)){

            cout << "Pop Successful.\n" << "id: " << data->id << "\ninformation: " << data->information << endl << endl;

        } else {

            //expected answer
            cout << "Pop Failed, underflower error, stack is empty.\n";
            cout << "expected id value: -1\n" << "recieved id value: " << data->id;
            cout << "\nexpected information value: \n" << "recieved information value: " << data->information << endl << endl;        
        }

        //TESTS WHEN STACK IS FULL

        cout << "\nTESTING FULL OPERATIONS\n-------------------------------\n";

        cout << "Filling stack...\n\n";

        for(int i = 0; i < size*1.5; i++) {
            rand_string(str);
            
            //expected both successful and failed
            if(stack.push(i, str)){

                 cout << "Push Succesful.\nid: " << i << "\ninformation: " << *str << "\n\n";

            } else {

                cout << "Push Failed.\n";
                *str == "" ? cout << "Invalid String.\n" : cout << "Overflow Error\n";
                cout << "Attempted push.\nid: " << i << "\ninformation: " << *str << "\n\n";
            }
        }

        if(stack.isEmpty()){

            cout << "Stack is empty.\n\n";

        } else {

            //expected answer
            cout << "Stack is NOT empty.\n\n";

        }

        if(stack.peek(data)){

            //expected answer
            cout << "Peek Successful.\n";
            cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

        } else {

            cout << "Peek Failed. Underflow Error.\n";

        }

        if(stack.pop(data)){

            //expected answer
            cout << "Pop Successful.\n";
            cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

        } else {

            cout << "Pop Failed. Underflow Error.\n";
        }

        //EMPTYING AND EMPTY TESTS

        cout << "\nCLEARING STACK...\n-------------------------------\n";

        for(int i = 0; i < size*1.5; i++){
            if(stack.peek(data)){

                //expected answer
                cout << "Peek Successful.\n";
                cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

            } else {

                cout << "Peek Failed. Underflow Error.\n\n";

            }

            if(stack.pop(data)){

                //expected answer
                cout << "Pop Successful.\n";
                cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

            } else {

                cout << "Pop Failed. Underflow Error.\n\n";
            }                        
        }

        if(stack.isEmpty()) {

            //expected answer
            cout << "\nStack is empty.\n";

        } else {

            cout << "\nStack is NOT empty.\n";

        }



        //MID STACK TESTS

        cout << "\nTESTING MIDDLE OF STACK...\n-------------------------------\n";
        
        for(int i = 0; i < size / 2; i++) {

            if(stack.push(i, str)){

                 cout << "Push Succesful.\nid: " << i << "\ninformation: " << *str << "\n\n";

            } else {

                cout << "Push Failed.\n";
                *str == "" ? cout << "Invalid String.\n" : cout << "Overflow Error\n";
                cout << "Attempted push.\nid: " << i << "\ninformation: " << *str << "\n\n";

            }

        }

        //NARROW BAND
        for(int i = 0; i < size*.30; i++) {

            if(stack.isEmpty()) {

                cout << "Stack is empty.\n";

            } else {

                cout << "Stack is NOT empty.\n";

            }

            cout << endl;

            if(stack.peek(data)){

                cout << "Peek Successful.\n";
                cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

            } else {

                cout << "Peek Failed. Underflow Error.\n";

            }

            if(stack.pop(data)){

                //expected answer
                cout << "Pop Successful.\n";
                cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

            } else {

                cout << "Pop Failed. Underflow Error.";
            }
            
            rand_string(str);

            if(stack.push(i, str)){

                 cout << "Push Succesful.\nid: " << i << "\ninformation: " << *str << "\n\n";

            } else {

                cout << "Push Failed.\n";
                *str == "" ? cout << "Invalid String.\n" : cout << "Overflow Error\n";
                cout << "Attempted push.\nid: " << i << "\ninformation: " << *str << "\n\n";

            }
        
        }

        //RANDOM TESTING
        cout << "TESTING RANDOMLY...\n-------------------------------\n";

        //clearing stack
        cout << "\nClearing Stack...\n\n";

        while(!stack.isEmpty()){
            if(stack.pop(data)){

                //expected answer
                cout << "Pop Successful.\n";
                cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

            } else {

                cout << "Pop Failed. Underflow Error.\n";
            }
        }

        cout << "Stack cleared.\n\n";

        //filling stack halfway
        for(int i = 0; i < size / 2; i++) {

            rand_string(str);

            if(stack.push(i, str)){

                cout << "Push Succesful.\nid: " << i << "\ninformation: " << *str << "\n\n";

            } else {

                cout << "Push Failed.\n";
                *str == "" ? cout << "Invalid String.\n" : cout << "Overflow Error\n";
                cout << "Attempted push.\nid: " << i << "\ninformation: " << *str << "\n\n";

            }               
        }

        int choice;

        for(int i = 0; i < size*10; i++){
            
            choice = rand() % 6 + 1;
            switch (choice) {

                case 1: //push

                    rand_string(str);
                    if(stack.push(i, str)){

                        cout << "Push Succesful.\nid: " << i << "\ninformation: " << *str << "\n\n";

                    } else {

                        cout << "Push Failed.\n";
                        *str == "" ? cout << "Invalid String.\n" : cout << "Overflow Error\n";
                        cout << "Attempted push.\nid: " << i << "\ninformation: " << *str << "\n\n";
                    }
                    break;

                case 2:

                case 3: //isEmpty

                    if(stack.isEmpty()) {

                        cout << "Stack is empty.\n\n";

                    } else {

                        cout << "Stack is NOT empty.\n\n";

                    }
                    break;
                    
                case 4: //pop

                    if(stack.pop(data)){

                        cout << "Pop Successful.\n";
                        cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

                    } else {

                        cout << "Pop Failed. Underflow Error.\n\n";
                    }
                    break;
                    
                case 5:
                    
                case 6: //peek

                    if(stack.peek(data)){

                        cout << "Peek Successful.\n";
                        cout << "id: " << data->id << "\ninformation: " << data->information << "\n\n";

                    } else {

                        cout << "Peek Failed. Underflow Error.\n\n";

                    }
                    break;

            }
        }
        
        cout << "\n\nTesting Complete \n\n";

        delete data;
        delete str;
        
    } else {

        cout << "ERROR, invalid input from command line.\nPlease enter one parameter, this parameter can only be an integer.\nEX: compliedFile 30\n";
    }

    return 0;
}