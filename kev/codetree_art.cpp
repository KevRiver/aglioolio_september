#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Coord{
    int y;
    int x;
};

struct Group{
    int color;
    vector<Coord> tiles;  
};

int N;
int board[29][29];
int group[29][29];
int group_cnt[900];
bool visited[29][29];

void rotate_square(int sy, int sx, int width){
    
    vector<vector<int>> square(width, vector<int>(width));
    // copy
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < width; ++j){
            square[i][j] = board[sy + i][sx + j];
        }
    }

    int y = width - 1, x = 0;
    for(int i = 0; i < width; ++i){
        y = width - 1;
        for(int j = 0; j < width; ++j){
            board[sy + i][sx + j] = square[y--][x];
        }
        ++x;
    }
}

void rotate_cross(){

    vector<vector<int>> board_copy(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            board_copy[i][j] = board[i][j];

    int y = 0, x = N - 1;
    for(int i = 0; i < N; ++i){
        y = 0;
        for(int j = 0; j < N; ++j){
            if(i == N/2 || j == N/2) 
                board[i][j] = board_copy[y][x];
            y++;
        }
        x--;
    }
}

void rotate(){
    const int di[4] = {0, 0, N/2 + 1, N/2 + 1};
    const int dj[4] = {0, N/2 + 1, 0, N/2 + 1};

    rotate_cross();
    for(int k = 0; k < 4; ++k){
        rotate_square(di[k], dj[k], N / 2);
    }
}

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};
void bfs(const Coord& start, int group_id){
    
    visited[start.y][start.x] = true;
    group[start.y][start.x] = group_id;
    group_cnt[group_id]++;

    int color = board[start.y][start.x];
    queue<Coord> q; q.push(start);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int k = 0; k < 4; ++k){
            int ny = cur.y + dy[k];
            int nx = cur.x + dx[k];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if(board[ny][nx] != color) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;

            group[ny][nx] = group_id;
            group_cnt[group_id]++;

            q.push({ny, nx});
        }
    }
}

void group_tiles(){

    // init visited
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            visited[i][j] = false;

    // init group_cnt
    for(int i = 0; i < 30; ++i)
        group_cnt[i] = 0;
    
    int group_id = 1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(visited[i][j]) continue;
            bfs({i, j}, group_id++);
        }
    }
}

int get_harmony_score(){

    vector<vector<bool>> tmp_visited(N, vector<bool>(N, false));
    
    int harmony_score = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(tmp_visited[i][j]) continue;
            tmp_visited[i][j] = true;
            
            for(int k = 0; k < 4; ++k){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(group[i][j] == group[ny][nx]) continue;

                harmony_score += (group_cnt[group[i][j]] + group_cnt[group[ny][nx]]) * board[i][j] * board[ny][nx];
            }
        }
    }
    return harmony_score/2;
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];

    int total_score = 0;
    int r = 0;
    do{
        group_tiles();
        total_score += get_harmony_score();
        rotate();
    }while(++r < 4);

    cout << total_score << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}