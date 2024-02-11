#include <iostream>
#include <queue>

using namespace std;
#define pii pair<int, int>
#define y first
#define x second


int h[500][500];
int dp[500][500];
int m, n;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int dfs(int y, int x){

    if(y == m-1 && x == n-1){
        return 1;
    }
    if(dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;
    for(int k = 0; k < 4; ++k){
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(h[ny][nx] >= h[y][x]) continue;
        dp[y][x] += dfs(ny, nx); 
    }
    return dp[y][x];
}

// 단순 dfs 최대 4^(500*500) 무조건 시간초과
int main(){

    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> h[i][j];
            dp[i][j] = -1;
        }
    }

    int answer = dfs(0, 0);

    cout << answer << '\n';

    return 0;
}