#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>
using namespace std;

#define pii pair<int, int>

struct Edge{
    int dest;
    int cost;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e, k;
    cin >> v >> e;
    cin >> k;
    vector<vector<Edge>> g(v+1);
    for(int i=0; i<e; ++i){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        g[src].push_back({dest, cost});
    }

    const int INF = INT_MAX;
    vector<int> dist(v+1, INF);
    function<void(int)> dijkstra = [&](int start){
        auto cmp = [](pii& l, pii& r){
            return l.second > r.second;
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        dist[start] = 0;
        pq.push({start, 0});
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            int cur = e.first;
            int cost = e.second;
            for(const Edge& edge: g[cur]){
                int dest = edge.dest;
                int cost = edge.cost;
                if(dist[dest] <= dist[cur] + cost) continue;
                dist[dest] = dist[cur] + cost;
                pq.push({dest, dist[dest]});
            }
        }
    };
    dijkstra(k);
    for(int i=1; i<=v; ++i){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}