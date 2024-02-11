#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < (int)wires.size(); i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> siz(n + 1);
    function<void(int, int)> dfs = [&](int cur, int prev) -> void
    {
        siz[cur] = 1;
        for (int nxt : graph[cur])
        {
            if (nxt == prev)
                continue;
            dfs(nxt, cur);
            siz[cur] += siz[nxt];
        }
    };
    dfs(1, -1);
    int answer = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j : graph[i])
        {
            int l = siz[j];
            int r = n - siz[j];
            answer = min(answer, abs(l - r));
        }
    }
    return answer;
}

// [[1, 3], [2, 3], [3, 4], [4, 5], [4, 6], [4, 7], [7, 8], [7, 9]]
int main()
{
    int n = 9;
    vector<vector<int>> wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};

    int answer = solution(n, wires);

    cout << answer << '\n';

    return 0;
}