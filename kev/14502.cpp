#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>

int n, m;
int lab[8][8];
vector<pii> pos;
vector<pii> virus;
int safe;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int simulate(const vector<pii>& virus){

    queue<pii> q;
    for(const pii& v: virus){
        q.push({v.first, v.second});
    }

    vector<pii> infected;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int k=0; k<4; ++k){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if(ny<0 || nx < 0 || ny >= n || nx >= m) continue;
            if(lab[ny][nx] != 0) continue;
            lab[ny][nx] = 2;
            q.push({ny, nx});
            infected.push_back({ny, nx});
        }
    }

    int ret = infected.size();
    for(const pii& p: infected){
        lab[p.first][p.second] = 0;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> lab[i][j];
            if(lab[i][j] == 0){
                ++safe;
                pos.push_back({i, j});
            } else if(lab[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }

    int answer = -1;
    int l = pos.size();
    for(int i=0; i<l-2; ++i){
        for(int j=i+1; j<l-1; ++j){
            for(int k=j+1; k<l; ++k){
                lab[pos[i].first][pos[i].second] = 1;
                lab[pos[j].first][pos[j].second] = 1;
                lab[pos[k].first][pos[k].second] = 1;

                int infected = simulate(virus);
                answer = max(answer, safe - 3 - infected);

                lab[pos[i].first][pos[i].second] = 0;
                lab[pos[j].first][pos[j].second] = 0;
                lab[pos[k].first][pos[k].second] = 0;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}