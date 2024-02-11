#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[100001][17]; // 2^17 = 1024 * 128 > 100000
int depth[100001];
int tree_height;

int log2(int n){
    // simple log2
    // n이 1이상의 자연수라고 가정한다
    if(n == 1) return 0;

    int x = 1, y = 0;
    while(x < n){ x *= 2; ++y;}

    return x == n ? y : y-1;
}

void init_tree(const vector<vector<int>>& adj){
    queue<int> q;
    parent[1][0] = 0;
    depth[1] = 0;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        tree_height = depth[node];
        for(int next: adj[node]){
            if(next == parent[node][0]) continue;
            parent[next][0] = node;
            depth[next] = depth[node] + 1;
            q.push(next);
        }
    }
}

int find_lca(int u, int v){
    if(depth[u] != depth[v]){
        if(depth[u] < depth[v])
            swap(u, v);
        
        while(depth[u] > depth[v]){
            int k = log2(depth[u] - depth[v]);
            u = parent[u][k];
        }
    }
    // depth를 맞추고 시작한다.

    if(u == v) return u;
    
    for(int k = log2(tree_height); k >= 0; --k){
        if(parent[u][k] == 0) continue;
        if(parent[u][k] == parent[v][k]) continue;
        u = parent[u][k];
        v = parent[v][k];
    } // k값을 줄여가며 2^k 번째 조상으로 u, v 값을 바꾼다. 루프를 다 돌면 u, v는 lca의 직계 자식 노드가 된다.

    return parent[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init_tree(adj);
    
    // 2^k = 2^(k-1) + 2^(k-1)
    for(int k=1; k<=log2(tree_height); ++k){
        for(int node=1; node<=n; ++node){
            if(parent[node][k-1] == 0) continue;
            parent[node][k] = parent[parent[node][k-1]][k-1];
        }
    }

    int m; cin >> m;
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        int lca = find_lca(u, v);
        cout << lca << '\n';
    }

    return 0;
}