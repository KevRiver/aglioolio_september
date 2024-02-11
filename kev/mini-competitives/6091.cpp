#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

struct Edge
{
    int src;
    int dest;
    int cost;

    bool operator>(const Edge &other) const
    {
        return cost > other.cost;
    }
};

int N;
int min_dist[1025][1025];
int roots[1025];
int depth[1025];
vector<Edge> edges;

int find_root(int node)
{
    if (roots[node] == node)
        return node;
    return roots[node] = find_root(roots[node]);
}

bool merge(int a, int b)
{
    int root_a = find_root(a);
    int root_b = find_root(b);

    if (root_a == root_b)
        return false;

    if (depth[root_a] < depth[root_b])
    {
        roots[a] = root_b;
    }
    else
    {
        roots[b] = root_a;
        if (depth[root_a] == depth[root_b])
            depth[root_a]++;
    }

    return true;
}

void init()
{
    cin >> N;

    for (int i = 1; i <= N - 1; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            int cost;
            cin >> cost;

            min_dist[i][j] = cost;
            min_dist[j][i] = cost;

            edges.push_back({i, j, cost});
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        roots[i] = i;
    }
}

void solve()
{
    sort(all(edges), greater<>());

    vector<vector<int>> answer(N + 1);

    while (!edges.empty())
    {
        Edge e = edges.back();
        edges.pop_back();

        int src = e.src;
        int dest = e.dest;

        if (merge(src, dest))
        {
            answer[src].push_back(dest);
            answer[dest].push_back(src);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(all(answer[i]));
        cout << answer[i].size() << " ";
        for (const auto &a : answer[i])
            cout << a << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}