#include <iostream>
using namespace std;

int gcd(int x, int y){
    return x % y == 0 ? y : gcd(y, x%y);
}
int lcm(int x, int y){
    return (x*y) / gcd(x, y);
}

int main(){
    int x, y;
    cin >> x >> y;
    if(x < y) swap(x, y);
    cout << gcd(x, y) << '\n';
    cout << lcm(x, y) << '\n';
    return 0;
}