#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

// 산성 용액 특성값 범위: 1 ~ 1,000,000,000
// 알칼리 용액 특성값 범위: -1 ~ -1,000,000,000
// 특성값으로 오름차순 정렬된 배열이 주어질 때,
// 서로 다른 두 용액을 선택하여 특성값을 0에 가장 가깝게 만드는 두 용액을 찾는다
// 주어진 용액의 특성값은 모두 다르다

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);

    for (auto &e : v)
        cin >> e;

    int min_dist = INT_MAX;
    int i, j;

    int l = 0, r = N - 1;
    while(l < r)
    {
        int dist = v[l] + v[r];

        if(abs(dist) <= min_dist)
        {
            min_dist = abs(dist);
            i = l;
            j = r;
        }

        if(dist == 0) break;
        else if(dist < 0) ++l;
        else --r;
    }

    cout << v[i] << " " << v[j] << '\n';
 
    return 0;
}