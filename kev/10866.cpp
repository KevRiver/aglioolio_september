#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

enum Operation{
    PUSH_FRONT,
    PUSH_BACK,
    POP_FRONT,
    POP_BACK,
    SIZE,
    EMPTY,
    FRONT,
    BACK
};

unordered_map<string, Operation> commands = {
    {"push_front", PUSH_FRONT},
    {"push_back", PUSH_BACK},
    {"pop_front", POP_FRONT},
    {"pop_back", POP_BACK},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK},
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s;
    deque<int> dq;
    for(int i=0; i<n; ++i){
        cin >> s;
        Operation operation = commands[s];
        switch (operation)
        {
        case PUSH_FRONT:
            {
                int x; cin >> x;
                dq.push_front(x);
            }
            break;
        case PUSH_BACK:
            {
                int x; cin >> x;
                dq.push_back(x);
            }
        break;
        case POP_FRONT:
            if(dq.empty()) cout << -1 << '\n';
            else {
                int evictor = dq.front();
                dq.pop_front();
                cout << evictor << '\n';
            }
        break;
        case POP_BACK:
            if(dq.empty()) cout << -1 << '\n';
            else{
                int evictor = dq.back();
                dq.pop_back();
                cout << evictor << '\n';
            }
        break;
        case FRONT:
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        break;
        case BACK:
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        break;
        case SIZE:
            cout << dq.size() << '\n';
        break;
        case EMPTY:
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
    }
    

    return 0;
}