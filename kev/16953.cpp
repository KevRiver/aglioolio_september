#include <iostream>
#include <queue>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

#define ll long long

struct Node{
    ll num;
    int op_cnt;
};

int bfs(ll a, ll b){
    int ret = INT_MAX;
    queue<Node> q;
    unordered_set<int> history;
    q.push({a, 0});
    history.insert(a);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        ll num = cur.num;
        int op_cnt = cur.op_cnt;

        if(num == b) return op_cnt+1;

        if(num > b) continue;
        if(history.find(num*2) == history.end()) {
            history.insert(num*2);
            q.push({num*2, op_cnt+1});
        }
        if(history.find(num*10+1) == history.end()) {
            history.insert(num*10+1);
            q.push({num*10+1, op_cnt+1});
        }
    }
    if(ret == INT_MAX) ret = -1;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    int answer = bfs(a, b);
    cout << answer << '\n';

    return 0;
}