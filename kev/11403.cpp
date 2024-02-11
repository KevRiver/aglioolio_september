#include <iostream>
#include <limits.h>

using namespace std;

int n;
int adj[100][100];
const int INF = INT_MAX / 2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> adj[i][j];
            if(adj[i][j] == 0)
                adj[i][j] = INF;
        }
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(adj[i][j] == INF) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}