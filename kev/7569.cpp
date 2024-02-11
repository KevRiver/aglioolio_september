#include <iostream>
#include <queue>

using namespace std;

int m, n, h;
int cnt;

struct Point{
    int z;
    int y;
    int x;
};

int tomato[100][100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> h;
    queue<Point> q;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    q.push({i, j, k});
                } else if(tomato[i][j][k] == 0){
                    ++cnt;
                }
            }
        }
    }

    int answer = 0;
    if(cnt == 0) {
        cout << answer << '\n';
        return 0;
    }

    while(!q.empty()){

        ++answer;
        int size = q.size();
        for(int i = 0; i < size; ++i){
            Point p = q.front();
            q.pop();

            for(int k = 0; k < 4; ++k){
                int nz = p.z;
                int ny = p.y + dy[k];
                int nx = p.x + dx[k];
                
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(tomato[nz][ny][nx] != 0) continue;
                tomato[nz][ny][nx] = 1;
                --cnt;
                q.push({nz, ny, nx});
            }

            for(int k = 0; k < 2; ++k){
                int nz = p.z + (k == 0 ? -1 : 1);
                int ny = p.y;
                int nx = p.x;

                if(nz < 0 || nz >= h) continue;
                if(tomato[nz][ny][nx] != 0) continue;
                tomato[nz][ny][nx] = 1;
                --cnt;
                q.push({nz, ny, nx});
            }
        }

        if(cnt == 0) break;
    }

    if(cnt > 0) answer = -1;
    cout << answer << '\n';

    return 0;
}