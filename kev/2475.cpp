#include <iostream>
using namespace std;

int main(){

    int answer = 0;
    for(int i=0; i<5; ++i){
        int n; cin >> n;
        answer += n * n % 10;
        answer %= 10;
    }

    cout << answer << '\n';

    return 0;
}