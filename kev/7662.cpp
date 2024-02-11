#include <iostream>
#include <set>
using namespace std;

void solve(){
    int k; cin >> k;

    multiset<int> q;
    for(int i=0; i<k; ++i){
        char cmd; cin >> cmd;
        int num; cin >> num;

        switch (cmd)
        {
        case 'I':
            // insert num
            q.insert(num);
            break;
        case 'D':
            // num == 1 ? delete top : delete bottom
            if(q.empty()) continue;
            auto it = q.end();
            --it; // pointing maximum
            if(num == -1) it = q.begin();
            q.erase(it);       
            break;
        }
    }

    if(q.empty()) cout << "EMPTY" << '\n';
    else cout << *(q.rbegin()) << " " << *(q.begin()) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    for(int i=0; i<t; ++i){
        solve();
    }

    return 0;
}