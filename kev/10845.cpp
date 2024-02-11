#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

enum Command{
    PUSH,
    POP,
    SIZE,
    EMPTY,
    FRONT,
    BACK
};

unordered_map<string, Command> cmd_map = {
    {"push", PUSH},
    {"pop", POP},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK},
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    queue<int> q;
    for(int i=0; i<n; ++i){
        string str; cin >> str;
        Command cmd = cmd_map[str];
        switch (cmd)
        {
        case PUSH:
            {
                int x; cin >> x;
                q.push(x);
            }
            break;
        case POP:
                if(q.empty()) cout << -1 << '\n';
                else{
                    cout << q.front() << '\n';
                    q.pop();
                }
            break;
        case SIZE:
            cout << q.size() << '\n';
            break;
        case EMPTY:
            cout << (q.empty() ? "1" : "0") << '\n';
            break;
        case FRONT:
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
            break;
        case BACK:
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
            break;
        }
    }
    return 0;
}