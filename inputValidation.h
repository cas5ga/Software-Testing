#ifndef inputValidation_H_
#define inputValidation_H_

void getInput(string a, string b, int& z){
    if(a == b){
        cout<<"Please enter the number " + a + ": ";
    }
    else{
        cout << "Please enter a number between " + a + " and " + b + ": ";
    }

    cin>>z;
}

int isInt(string a, string b){
    int z = 0;

    getInput(a,b,z);

    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << endl << "Error. Please enter a number between " + a + " and " + b + ": ";
        cin>>z;
    }
 return z;
}

int inRange(int a, int b){
    bool goodInput = false;
    int input;
    do{
        input = isInt(to_string(a), to_string(b));
        if(input >= a && input <= b){
            goodInput = true;
        }
    }while(!goodInput);

    return input;
}

//I don't really know how to test these without massively rewriting them.
//I'm fine with one round of "manual" testing that isn't automated, and these functions
//Have most definitely stood the test of time.


#endif
