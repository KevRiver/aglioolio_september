#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> seq(N);
    for (auto &e : seq)
        cin >> e;

    vector<int> lis;
    int len = 0;

    for (int i = 0; i < N; ++i)
    {
        if (lis.empty() || lis.back() < seq[i])
        {
            lis.push_back(seq[i]);
            continue;
        }

        int l = 0, r = lis.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(lis[mid] >= seq[i]) r = mid;
            else l = mid + 1;
        }
        lis[l] = seq[i];
    }

    cout << lis.size() << '\n';

    return 0;
}