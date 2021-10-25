#include <iostream>
#include <fstream>
using namespace std;
char pop_value;
struct OBJ {
    char d;
    OBJ* next;
};
OBJ* top;
OBJ* push (int data) {
    OBJ* ptr = new OBJ;
    ptr -> d = data;
    ptr -> next = top;
    top = ptr;
    return ptr;
}
void pop () {
    if (top == NULL) return ;
    pop_value = top -> d;
    OBJ* buffer = top -> next;
    delete top;
    top = buffer;
}
 
int main(int argc, const char * argv[]) {
    ifstream fin ("/Users/artemparfenov/Desktop/AaSD_Lab_3(4)/problem_postfix/problem_postfix/postfix_in.txt");
    ofstream fout ("/Users/artemparfenov/Desktop/AaSD_Lab_3(4)/problem_postfix/problem_postfix/postfix_out.txt");
    char buffer_var;
    char variable1, variable2;
    fin >> buffer_var;
    while (!fin.eof()) {
        
        if (buffer_var < 48) {
            pop();
            variable1 = int (pop_value) - 48;
            pop();
            variable2 = int (pop_value) - 48;
            if (buffer_var == '+') {
                push(variable1 + variable2);
                cout << variable1 + variable2 << endl;
            }
            else if (buffer_var == '-') {
                push(variable1 - variable2);
                cout << variable1 - variable2 << endl;
            }
            else if (buffer_var == '*') {
                push(variable1 * variable2);
                cout << variable1 * variable2 << endl;
            }
        }
        else {
            push (buffer_var);
            cout << char(top -> d) << endl;
        }
        fin >> buffer_var;
    }
    cout << int(top -> d) << endl;
    return 0;
}
