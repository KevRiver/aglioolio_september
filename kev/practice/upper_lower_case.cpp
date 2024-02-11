#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;

bool is_alphabet(char ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main(){
    string str = "a b me";
    
    size_t start, pos = 0;
    while((start = str.find_first_not_of(" \n\0", pos)) != string::npos){
        pos = str.find_first_of(" \n\0", start + 1);
        for(size_t i = start; i < pos && i < str.size(); ++i){
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}