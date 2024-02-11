#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
char MAP[5][5];

void init()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> MAP[i][j];
        }
    }
}

struct Node
{
    int y;
    int x;
    int value;
    char symbol;
};

const int dy[2] = {0, 1}; // right, down
const int dx[2] = {1, 0};

void solve()
{
    int max_path_value = INT_MIN, min_path_value = INT_MAX;

    queue<Node> q;
    q.push({0, 0, MAP[0][0] - '0', ' '});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int k = 0; k < 2; ++k)
        {
            int ny = cur.y + dy[k];
            int nx = cur.x + dx[k];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if ((ny + nx) % 2 != 0)
            {
                q.push({ny, nx, cur.value, MAP[ny][nx]});
            }
            else
            {
                int num = MAP[ny][nx] - '0';
                
                int result;

                if (cur.symbol == '*')
                    result = cur.value * num;
                else if (cur.symbol == '+')
                    result = cur.value + num;
                else if (cur.symbol == '-')
                    result = cur.value - num;

                if (ny == N - 1 && nx == N - 1)
                {
                    min_path_value = min(min_path_value, result);
                    max_path_value = max(max_path_value, result);
                    continue;
                }

                q.push({ny, nx, result, ' '});
            }
        }
    }

    cout << max_path_value << " " << min_path_value << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}