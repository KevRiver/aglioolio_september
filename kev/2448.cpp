#include <iostream>
using namespace std;

struct Point{
    int y;
    int x;
};

void triangle(vector<vector<char>>& grid, Point pos, int h){
    if(h == 3){
        for(int j=0; j<5; ++j){
            if(j == 2) grid[pos.y][pos.x + j] = '*';
            if(j % 2 == 1) grid[pos.y+1][pos.x + j] = '*';
            grid[pos.y+2][pos.x + j] = '*';
        }
        return;    
    }
    int w = 2*h-1;
    triangle(grid, {pos.y, pos.x + w/4 + 1}, h/2);
    triangle(grid, {pos.y+h/2, pos.x}, h/2);
    triangle(grid, {pos.y+h/2, pos.x + w/2 + 1}, h/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(2*n-1, ' '));

    triangle(grid, {0, 0}, n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<2*n-1; ++j){
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}