#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    map<int, string> m = {
        {1, "one"},
        {3, "three"},
        {5, "five"},
        {10, "ten"},
        {15, "fifteen"},
        {20, "twelve"}
    };

    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << '\n';
    }

    auto it = m.lower_bound(4);
    cout << it->first << " " << it->second << '\n';
    advance(it, -1);
    cout << it->first << " " << it->second << '\n';
    

    return 0;
}