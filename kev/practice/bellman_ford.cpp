#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const int INF = 25'000'001;

struct Edge{
    int e;
    int t;
};

bool is_negative_cycle_exist(const vector<vector<Edge>>& graph, int s){
    // 음의 사이클이 존재, 존재하지 않음 판별
    const int n = graph.size();
    const int v = n - 1;
    
    vector<int> distance(n, INF);
    distance[s] = 0;

    for(int i = 0; i < v - 1; ++i){
        for(int node = 1; node < n; ++node){
            for(const auto& edge: graph[node]){
                int neighbor = edge.e;
                int time = edge.t;
                if(distance[node] + time < distance[neighbor]){
                    distance[neighbor] = distance[node] + time;
                }
            }
        }
    }

    for(int node = 1; node < n; ++node){
        for(const auto& edge: graph[node]){
            int neighbor = edge.e;
            int time = edge.t;
            if(distance[neighbor] > distance[node] + time)
                return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<Edge>> graph(n + 1);
        for(int i=0; i<m; ++i){
            int s, e, t; 
            cin >> s >> e >> t;
            graph[s].push_back({e, t});
            graph[e].push_back({s, t});
        }
        for(int i=0; i<w; ++i){
            int s, e, t;
            cin >> s >> e >> t;
            graph[s].push_back({e, -t});
        }
        if(is_negative_cycle_exist(graph, 1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}