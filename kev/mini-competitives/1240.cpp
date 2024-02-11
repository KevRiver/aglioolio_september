#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N, M;
void solve(){
    cin >> N >> M;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX / 2));
    for(int i = 1; i <= N; ++i) dist[i][i] = 0;

    for(int i = 0; i < N - 1; ++i){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        dist[src][dest] = cost;
        dist[dest][src] = cost;
    }

    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(dist[i][j] <= dist[i][k] + dist[k][j]) continue;
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i = 0; i < M; ++i){
        int src, dest;
        cin >> src >> dest;
        cout << dist[src][dest] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}