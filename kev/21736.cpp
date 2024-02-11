#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pii pair<int, int>

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

char campus[600][600];
bool visited[600][600];
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    queue<pii> q;
    vector<pii> people;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                q.push({i, j});
            }
        }
    }

    int answer = 0;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int k=0; k<4; ++k){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if(ny<0 || nx<0 || ny >= n || nx >= m) continue;
            if(campus[ny][nx] == 'X') continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if(campus[ny][nx] == 'P') ++answer;
            q.push({ny, nx});
        }
    }

    if(answer == 0) cout << "TT" << '\n';
    else cout << answer << '\n';

    return 0;
}