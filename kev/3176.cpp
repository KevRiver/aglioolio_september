#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int parent[100001][17]; // 100001 * 17 * 4 byte ~= 6.5 MB
int depth[100001]; // 100001 * 4 byte ~= 0.3 MB
int min_road[100001][17]; // 6.5 MB
int max_road[100001][17]; // 6.5 MB
int tree_height;

int log2(int n){
    if(n == 1) return 0;
    int x = 1;
    int y = 0;
    while(x < n) {x *= 2; ++y;}
    return x == n ? y : y-1;
}

struct Minmax{
    int min;
    int max;
};

Minmax get_minmax(int u, int v){

    Minmax ret = {1000001, 0};

    if(depth[u] != depth[v]){
        if(depth[u] < depth[v])
            swap(u, v);
        
        while(depth[u] > depth[v]){
            int k = log2(depth[u] - depth[v]);
            ret.min = min(ret.min, min_road[u][k]);
            ret.max = max(ret.max, max_road[u][k]);
            u = parent[u][k];
        }
    }

    if(u == v) return ret;
    
    for(int k = log2(tree_height); k >= 0; --k){
        if(parent[u][k] == 0) continue;
        if(parent[u][k] == parent[v][k]) continue;
        
        Minmax u_k = {min_road[u][k], max_road[u][k]};
        Minmax v_k = {min_road[v][k], max_road[v][k]};
        
        int less = u_k.min < v_k.min ? u_k.min : v_k.min;
        int greater = u_k.max > v_k.max ? u_k.max : v_k.max;

        ret.min = min(ret.min, less);
        ret.max = max(ret.max, greater);

        u = parent[u][k];
        v = parent[v][k];
    }

    int less = min(min_road[u][0], min_road[v][0]);
    int greater = max(max_road[u][0], max_road[v][0]);

    ret.min = min(ret.min, less);
    ret.max = max(ret.max, greater);

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<unordered_map<int, int>> adj(n+1);
    for(int i=0; i<n-1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    int m; cin >> m;
    vector<pair<int, int>> queries(m);
    for(int i=0; i<m; ++i){
        cin >> queries[i].first >> queries[i].second;
    } 


    queue<int> q;
    parent[1][0] = 0;
    depth[1] = 0;
    q.push(1);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        tree_height = depth[a];
        for(const auto& next: adj[a]){
            int b = next.first;
            int c = next.second;

            if(b == parent[a][0]) continue;
            
            parent[b][0] = a;
            depth[b] = depth[a] + 1;
            min_road[b][0] = max_road[b][0] = c;
            
            q.push(b);
        }
    }

    
    for(int k=1; k<=log2(tree_height); ++k){
        for(int node = 1; node <= n; ++node){
            if(parent[node][k-1] == 0) continue;

            parent[node][k] = parent[parent[node][k-1]][k-1];
            
            min_road[node][k] = min(min_road[node][k-1], min_road[parent[node][k-1]][k-1]);
            max_road[node][k] = max(max_road[node][k-1], max_road[parent[node][k-1]][k-1]);
        }
    }

    for(const auto& query: queries){
        int u = query.first;
        int v = query.second;

        Minmax answer = get_minmax(u, v);

        cout << answer.min << " " << answer.max << '\n';
    }

    return 0;
}