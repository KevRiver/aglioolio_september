#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;

#define pii pair<int, int>

int next_location(int loc, int k){
    if(k == 0) return loc+1;
    if(k == 1) return loc-1;
    return loc*2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int max_loc = N > K ? N+(N-K+1) : K+(K-N+1);
    
    const int INF = INT_MAX;
    vector<int> t(max_loc+1, INF);

    function<pair<int,int>(int, int)> bfs = [&](int start, int end){    
        int min_t = INF;
        int cnt = 0;
        
        queue<pii> q;
        q.push({start, 0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int loc = p.first;
            int cur_t = p.second;

            if(t[loc] < cur_t) continue;
            t[loc] = cur_t;
            
            if(loc == end){
                if(cur_t < min_t) {min_t = cur_t; cnt = 1;}
                else if(cur_t == min_t) {++cnt;}
                continue;
            }

            for(int k=0; k<3; ++k){
                int nloc = next_location(loc, k);
                if(loc == nloc) continue;
                if(nloc < 0 || nloc > max_loc) continue;
                if(t[nloc] < cur_t+1) continue;
                q.push({nloc, cur_t+1});
            }
        }
        return make_pair(min_t, cnt);
    };

    pii answer = bfs(N, K);
    cout << answer.first << '\n' << answer.second << '\n';

    return 0;
}