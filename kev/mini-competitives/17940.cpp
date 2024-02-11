#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    int station;
    int transfer_cnt;
    int time_spent;

    bool operator<(const Node &other) const
    {
        if (transfer_cnt < other.transfer_cnt)
            return true;
        if (transfer_cnt > other.transfer_cnt)
            return false;
        if (time_spent < other.time_spent)
            return true;
        if (time_spent > other.time_spent)
            return false;
        return false;
    }

    bool operator>(const Node &other) const
    {
        if (transfer_cnt > other.transfer_cnt)
            return true;
        if (transfer_cnt < other.transfer_cnt)
            return false;
        if (time_spent > other.time_spent)
            return true;
        if (time_spent < other.time_spent)
            return false;
        return false;
    }
};

int N, M;
int edge[1001][1001];
int company[1001];

unordered_map<int, Node> dist;

void init()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> company[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> edge[i][j];
}

void dijkstra(int start)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0, 0});
    dist[start] = {start, 0, 0};

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        // push next nodes
        for (int d = 0; d < N; ++d)
        {
            if (edge[cur.station][d] == 0)
                continue;

            Node next;
            next.station = d;
            next.time_spent = cur.time_spent + edge[cur.station][next.station];
            next.transfer_cnt = cur.transfer_cnt;
            if (company[cur.station] != company[next.station])
                next.transfer_cnt++;

            if (dist.find(d) == dist.end() || dist[d] > next)
            {
                dist[d] = next;
                pq.push(next);
            }
        }
    }
}

void solve()
{
    dijkstra(0);

    auto &answer = dist[M];

    cout << answer.transfer_cnt << " " << answer.time_spent << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}