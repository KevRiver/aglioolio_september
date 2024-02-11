#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define pii pair<int, int>

int n;
char grid[100][100];
bool visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

void bfs(int i, int j, bool flag){

    char color1 = grid[i][j];
    char color2 = color1;
    if(flag && (color1 == 'G' || color2 == 'R')){
        color2 = color1 == 'G' ? 'R' : 'G';
    }

    visited[i][j] = true;

    queue<pii> q;
    q.push({i, j});
    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int k=0; k<4; ++k){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(grid[ny][nx] != color1 && grid[ny][nx] != color2) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> grid[i][j];
        }
    }
    
    int answer[] = {0, 0};

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(visited[i][j]) continue;
            answer[0]++;
            bfs(i, j, false);
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(visited[i][j]) continue;
            answer[1]++;
            bfs(i, j, true);
        }
    }

    cout << answer[0] << " " << answer[1] << '\n';    

    return 0;
}