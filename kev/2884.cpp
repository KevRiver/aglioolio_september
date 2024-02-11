#include <iostream>
using namespace std;

int main(){

    int hh, mm;
    cin >> hh >> mm;

    mm -= 45;
    if(mm < 0){
        hh = (24 + hh - 1) % 24;
        mm += 60;
    }
    cout << hh << " " << mm << '\n';
    
    

    return 0;
}