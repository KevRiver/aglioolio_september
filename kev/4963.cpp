#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define pii pair<int, int>

/**
 * -1,-1    -1,0,   -1,1
 * 0,-1     y,x     0,1 
 * 1,-1     1,0     1,1
 */
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int w, h;
char m[50][50];
bool visited[50][50];

void bfs(int y, int x){
    queue<pii> q;
    q.push({y, x});
    visited[y][x] = true;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int k=0; k<8; ++k){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(m[ny][nx] == '0' || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        memset(m, 0, sizeof(m));
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> m[i][j];
            }
        }

        int cnt = 0;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(m[i][j] == '0' || visited[i][j]) continue;
                bfs(i, j);
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}