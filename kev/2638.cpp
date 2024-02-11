#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int N, M;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<pii> cheeze;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                cheeze.push_back({i, j});
            }
        }
    }


    function<void(pii)> bfs = [&](pii start){
        
        if(grid[start.first][start.second] == -1) return;
        grid[start.first][start.second] = -1;
        
        queue<pii> q; q.push(start);
        
        while(!q.empty()){
            pii cur = q.front();
            q.pop();
            
            int y = cur.first;
            int x = cur.second;
            
            for(int k=0; k<4; ++k){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(grid[ny][nx] != 0) continue;
                grid[ny][nx] = -1;
                q.push({ny, nx});
            }
        }
    };

    bfs({0, 0});
   
    int answer = 0;
    vector<pii> tmp;
    while(!cheeze.empty()){
        
        for(int i=0; i<cheeze.size(); ++i){
            int y = cheeze[i].first;
            int x = cheeze[i].second;
            
            int cnt = 0;
            for(int k=0; k<4; ++k){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(grid[ny][nx] == -1) ++cnt;
            }

            if(cnt >= 2) {
                tmp.push_back({y, x});
                cheeze[i].first = -1;
                cheeze[i].second = -1;
            }
        }

        auto it = remove_if(begin(cheeze), end(cheeze), [](pii& e){
            return e.first == -1 && e.second == -1;
        });
        cheeze.erase(it, end(cheeze));
        ++answer;

        for(int i=0; i<tmp.size(); ++i){
            int y = tmp[i].first;
            int x = tmp[i].second;
            grid[y][x] = 0;
        }

        while(!tmp.empty()){
            pii start = tmp.back();
            tmp.pop_back();
            bfs(start);
        }
    }

    cout << answer << '\n';

    return 0;
}