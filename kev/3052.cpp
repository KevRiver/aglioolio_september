#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int> nums;
    for(int i=0; i<10; ++i){
        int n; cin >> n;
        nums.insert(n % 42);
    }
    cout << nums.size() << '\n';

    return 0;
}