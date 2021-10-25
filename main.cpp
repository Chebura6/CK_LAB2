#include <iostream>
#include <fstream>
using namespace std;
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
    if (top == NULL) return;
    OBJ* buffer = top -> next;
    delete top;
    top = buffer;
}
int main(int argc, const char * argv[]) {
    ifstream fin ("binsearch.in");
    ofstream fout ("binsearch.out");
    int yes_or_no = 0; // 1 - no, 0 - yes;
    char buf_symbol;
    while (!fin.eof()) {
        buf_symbol = fin.get();
        if (((buf_symbol == '(') || (buf_symbol == '[')) && (yes_or_no == 0)) {
            push (buf_symbol);
//            cout << "pushing" << "\n";
        }
        else if (((buf_symbol == ')') || (buf_symbol == ']')) && (yes_or_no == 0)) {
            if (top != NULL) {
                if ((buf_symbol == ')') && (top -> d == '(')) {
                    pop();
//                    cout << "poping" << "\n";
                }
                else if ((buf_symbol == ']') && (top -> d == '[')) {
                    pop();
//                    cout << "poping2" << "\n";
                }
                else if ((buf_symbol == ']') && (top -> d == '(')) {
                    yes_or_no++;
                }
                else if ((buf_symbol == ')') && (top -> d == '[')) {
                    yes_or_no++;
                }
            }
            else yes_or_no++;
        }
        else if (buf_symbol == '\n') {
            if ((yes_or_no == 0) && (top == NULL)) fout << "YES" << endl;
            else fout << "NO" << endl;
            yes_or_no = 0;
            top = NULL;
        }
//        cout << buf_symbol;
    }

    return 0;
}
