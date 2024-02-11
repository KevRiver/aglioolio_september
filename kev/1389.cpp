#include <iostream>
#include <limits.h>

using namespace std;

int n, m;

int adj[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            adj[i][j] = INT_MAX / 2;
        }
    }

    for(int i=0; i<m; ++i){
        int a; cin >> a;
        int b; cin >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            if(i == k) continue;
            for(int j = 1; j <= n; ++j){
                if(i == j || j == k) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int answer = 1;
    int min_score = 0;
    for(int j = 2; j <= n; ++j){
        min_score += adj[1][j];
    }

    for(int i = 2; i <= n; ++i){
        int score = 0;
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            score += adj[i][j];
        }

        if(score < min_score){
            min_score = score;
            answer = i;
        }
    }
    
    cout << answer << '\n';

    return 0;
}