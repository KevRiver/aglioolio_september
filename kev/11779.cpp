#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define pii pair<int, int>

struct Edge{
    int dest;
    int cost;
};

int N, M;

vector<vector<Edge>> adj;
vector<int> dist;
vector<int> root;

void dijkstra(int start, int end){

    auto cmp = [](pii& l, pii& r){
        return l.second > r.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    pq.push({start, 0});
    root[start] = 0;
    dist[start] = 0;

    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();

        int cur = p.first;
        int cur_cost = p.second;
        if(dist[cur] < cur_cost) continue;

        for(Edge& edge: adj[cur]){
            int next = edge.dest;
            int cost = edge.cost;

            if(dist[next] <= cur_cost + cost) continue;

            root[next] = cur;
            dist[next] = cur_cost + cost;
            
            pq.push({next, cur_cost + cost});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int INF = INT_MAX;

    cin >> N;
    cin >> M;
    adj.resize(N+1);
    dist.resize(N+1); for(int i=0; i<N+1; ++i) dist[i] = INF;
    root.resize(N+1); for(int i=0; i<N+1; ++i) root[i] = 0;

    for(int i=0; i<M; ++i){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        adj[src].push_back({dest, cost});
    }
    int start, end;
    cin >> start >> end;

    dijkstra(start, end);

    vector<int> path;
    int node = end;
    while(node != 0){
        path.push_back(node);
        node = root[node];
    }

    cout << dist[end] << '\n';
    cout << path.size() << '\n';
    for(int i = path.size()-1; i >= 0; --i) cout << path[i] << " ";
    cout << '\n';

    return 0;
}