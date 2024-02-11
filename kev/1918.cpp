#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> priority = {
    {'+', 0},
    {'-', 0},
    {'*', 1},
    {'/', 1}
};

bool is_operator(char ch){
    return ch == '+' 
        || ch == '-' 
        || ch == '*' 
        || ch == '/' 
        || ch == '(' 
        || ch == ')';
}

void postfix(string expr){
    stack<char> operators;
    for(char c: expr){
        if(!is_operator(c)) {
            cout << c;
            continue;
        }

        if(operators.empty()){
            operators.push(c);
            continue;
        }

        if(c == '(') {
            operators.push(c);
            continue;
        }

        if(c == ')'){
            while(operators.top() != '('){
                cout << operators.top();
                operators.pop();
            }
            operators.pop();
            continue;
        }

        while(!operators.empty()
        && operators.top() != '('
        && (priority[operators.top()] >= priority[c])){
            cout << operators.top();
            operators.pop();
        }
        operators.push(c);
    }
    while(!operators.empty()){
        cout << operators.top();
        operators.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string expr; cin >> expr;
    postfix(expr);

    return 0;
}