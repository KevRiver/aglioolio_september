#include <iostream>
using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    int n = a * b * c;

    int cnt[10] = {0, };
    while(n > 0){
        cnt[n % 10]++;
        n /= 10;
    }
    for(int i=0; i<10; ++i){
        cout << cnt[i] << '\n';
    }

    return 0;
}