#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto is_end_string = [](const string& str){
        return str == ".";
    };

    vector<string> phrases;
    for(string str; getline(cin, str) && !is_end_string(str);){
        
        phrases.push_back(str);
    }

    auto is_balanced = [](const string& str){
        stack<char> opened;
        for(char c: str){

            if(c != '[' && c != '(' && c != ']' && c != ')') continue;

            if(c == '[' || c == '('){
                opened.push(c);
                continue;
            }

            if(opened.empty()) return false;
            if(c == ']' && opened.top() != '[') return false;
            if(c == ')' && opened.top() != '(') return false;

            opened.pop();
        }
        return opened.empty();
    };

    for(const string& ph: phrases){
        if(is_balanced(ph)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}