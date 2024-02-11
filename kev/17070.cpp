#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

enum PipeAlignment{
    HORIZONTAL = 0,
    VERTICAL,
    DIAGONAL
};

struct Point{
    int y;
    int x;
};

struct Pipe{
    Point start;
    Point end;
    PipeAlignment alignment;
};

const vector<vector<Point>> next_start = {
    {{0, 1}, {0, 1}}, // horizontal
    {{1, 0}, {1, 0}}, // vertical
    {{1, 1}, {1, 1}, {1, 1}} // diagonal
};
const vector<vector<Point>> next_end = {
    {{0, 1}, {1, 1}}, // horizontal
    {{1, 0}, {1, 1}}, // vertical
    {{0, 1}, {1, 0}, {1, 1}} // diagonal
};
const vector<vector<PipeAlignment>> next_alignment = {
    {HORIZONTAL, DIAGONAL},
    {VERTICAL, DIAGONAL},
    {HORIZONTAL, VERTICAL, DIAGONAL}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int grid[17][17] = {0, };
    
    int N; cin >> N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin >> grid[i][j];
        }
    }

    function<int(Pipe)> bfs = [&](Pipe start){
        queue<Pipe> q;
        q.push(start);
        int cnt = 0;
        while(!q.empty()){
            Pipe p = q.front();
            q.pop();

            Point s = p.start;
            Point e = p.end;
            PipeAlignment a = p.alignment;
            
            int k = a == DIAGONAL ? 3 : 2; 
            const vector<Point>& ds = next_start[a];
            const vector<Point>& de = next_end[a];
            const vector<PipeAlignment>& da = next_alignment[a];
            for(int i=0; i<k; ++i){
                Point ns = {s.y + ds[i].y, 
                            s.x + ds[i].x};

                Point ne = {e.y + de[i].y, 
                            e.x + de[i].x};

                PipeAlignment na = da[i];

                if(ns.y < 1 || ns.y > N || ns.x < 1 || ns.x > N) continue;
                if(ne.y < 1 || ne.y > N || ne.x < 1 || ne.x > N) continue;
                if(grid[ns.y][ns.x] == 1 || grid[ne.y][ne.x] == 1) continue;
                if(na == DIAGONAL && (grid[ns.y][ns.x+1] == 1 || grid[ns.y+1][ns.x] == 1)) continue;

                if(ne.y == N && ne.x == N) ++cnt;
                else q.push({ns, ne, na});
            }
        }
        return cnt;
    };
    
    int answer = bfs({{1, 1}, {1, 2}, HORIZONTAL});
    cout << answer << '\n';
    
    return 0;
}