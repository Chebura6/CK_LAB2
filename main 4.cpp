#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int pop_value;
struct OBJ {
    int d;
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
    int int_var1, int_var2;
    int variable1, k = 0;
    vector <int> comparable_numbers ;
    int vector_elements_counter;
    fin >> buffer_var;
    while (!fin.eof()) {
        if (buffer_var < 48) {
            if (k == 0) {
                pop();
                int_var1 = pop_value - 48;
                pop();
                int_var2 = pop_value - 48;
                k++;
            }
            else {
                pop();
                for (int i = 0; i < vector_elements_counter; i++) {
                    if (comparable_numbers[i] == pop_value) {
                        int_var1 = pop_value;
                        break;
                    }
                    else int_var1 = pop_value - 48;
                }
                pop();
                for (int i = 0; i < vector_elements_counter; i++) {
                    if (comparable_numbers[i] == pop_value) {
                        int_var2 = pop_value;
                        break;
                    }
                    else int_var2 = pop_value - 48;
                }
            }
            if (buffer_var == '+') {
                variable1 = int_var2 + int_var1;
                push(variable1);
                comparable_numbers.push_back (variable1);
                vector_elements_counter++;
//                push(int_var1 + int_var2);
//                cout << int_var1 + int_var2 << endl;
//                cout << char(top -> d) << endl;
            }
            else if (buffer_var == '-') {
                variable1 = int_var2 - int_var1;
                push(variable1);
                comparable_numbers.push_back (variable1);
                vector_elements_counter++;
//                cout << int_var2 - int_var1 << endl;
//                cout << char(top -> d) << endl;
            }
            else if (buffer_var == '*') {
                variable1 = int_var2 * int_var1;
                push(variable1);
                comparable_numbers.push_back (variable1);
                vector_elements_counter++;
//                push(int_var1 * int_var2);
//                cout << int_var1 * int_var2 << endl;
//                cout << char(top -> d) << endl;
            }
        }
        else {
            push (buffer_var);
//            cout << char(top -> d) << endl;
        }
        fin >> buffer_var;
    }
//    cout << int(top -> d) << endl;

    return 0;
}
