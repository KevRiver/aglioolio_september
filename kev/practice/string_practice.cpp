#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string str = "abcde";
    cout << str.substr(2) << '\n'; // 2번 인덱스부터 시작하는 부분 문자열
    cout << str.substr(3) << '\n';
    
    return 0;
}