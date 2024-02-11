#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // a^2 + b^2 = c^2 이면 직각삼각형
    int leg[3];
    while(true){
        cin >> leg[0] >> leg[1] >> leg[2];
        if(leg[0] == 0 && leg[1] == 0 && leg[2] == 0) break;
        sort(leg, leg + 3);
        int a = leg[0], b = leg[1], c = leg[2];
        if(a*a + b*b == c*c) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
    return 0;
}