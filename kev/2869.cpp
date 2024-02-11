#include <iostream>
using namespace std;

int main(){
    
    int a, b, v;
    cin >> a >> b >> v;
    int height_per_day = a-b;
    int t = (v-a)/height_per_day 
                + ((v-a) % height_per_day == 0 ? 0 : 1) 
                + 1;
    cout << t << '\n';

    return 0;
}