
#include<iostream>
#include<stack>
using namespace std;

string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    for(int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if(isalnum(c)) {
            s.push(string(1, c));
        } else {
            if(s.size() < 2) {
                cerr << "Error: Invalid prefix expression\n";
                return "";
            }
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            s.push("(" + op1 + c + op2 + ")");
        }
    }

    if(s.size() != 1) {
        cerr << "Error: Invalid prefix expression\n";
        return "";
    }

    return s.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    string infix = prefixToInfix(prefix);

    if(!infix.empty()) {
        cout << "Infix Expression: " << infix << endl;
    }

    return 0;
}
























// #include<iostream>
// #include<stack>
// using namespace std;

// string prefixToInfix( string prefix) {
//     stack<string> s;
//     int n = prefix.size();

//     for( int i=n-1; i>=0; i++) {
//         char c = prefix[i];
        
//         if(isalnum(c)) {
//             s.push(string(1, c));
//         } else {
//             string op1 = s.top(); s.pop();
//             string op2 = s.top(); s.pop();

//             s.push("(" + op1 + c + op2 + ")");
//         }
//     }

//     return s.top();
// }

// int main() {
//     string prefix = "*-A/BC-C/AKL";
//     cout <<"Infix Expression: " << prefixToInfix(prefix) << endl;

//     return 0;
// }