#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int, int>

struct Ice{
    int y;
    int x;
    int life;
};

int n, m;
int arr[300][300];
bool visited[300][300];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

void bfs(int i, int j){
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int k = 0; k < 4; ++k){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(arr[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    queue<Ice> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
            if(arr[i][j] > 0){
                q.push({i, j, arr[i][j]});
            }
        }
    }

    int t = 0;
    while(!q.empty()){
        // melt
        int size = q.size();
        for(int i = 0; i < size; ++i){
            Ice cur = q.front();
            q.pop();

            int ocean = 0;
            for(int k = 0; k < 4; ++k){
                int ny = cur.y + dy[k];
                int nx = cur.x + dx[k];
                
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(arr[ny][nx] == 0) ++ocean;
            }

            int next_life = cur.life - ocean;
            q.push({cur.y, cur.x, next_life > 0 ? next_life : 0});
        }

        // update
        size = q.size();
        for(int i = 0; i < size; ++i){
            Ice ice = q.front();
            q.pop();

            arr[ice.y][ice.x] = ice.life;
            if(ice.life > 0) q.push(ice);
        }

        ++t;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                visited[i][j] = false;
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(arr[i][j] == 0) continue;
                if(visited[i][j]) continue;
                visited[i][j] = true;

                bfs(i, j);

                ++cnt;
            }
        }

        if(cnt >= 2){
            cout << t << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}