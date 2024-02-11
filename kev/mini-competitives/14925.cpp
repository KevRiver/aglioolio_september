#include <iostream>
using namespace std;


int M, N;
void solve(){
    cin >> M >> N;
    vector<vector<int>> field(M, vector<int>(N, 0));
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> field[i][j];
        }
    }

    vector<vector<int>> grid(M, vector<int>(N, 0));

    const int dy[3] = {-1, -1, 0};
    const int dx[3] = {0, -1, 0};
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(field[i][j] != 0) 
            for(int k = 0; k < 3; ++k){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny < 0 || nx < 0 || ny >= M || nx >= N){
                    l[i][j] = 1;
                    continue;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}