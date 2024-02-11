#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define pii pair<int, int>


// h = ceil(log2(n)) (높이는 0부터 시작, 트리의 총 높이는 h + 1), arr size = 2^(h+1)-1;
// ceil(log2(100,000)) = 17, max arr size = 2^(18) (node 1부터 시작)
int pow2(int exp){
    if(exp == 0) return 1;
    int r = 1;
    for(int e = 0; e < exp; ++e) r *= 2;
    return r;
}

int segtree_arr_size(int x){
    int k = 1;
    int exp;
    for(exp = 0; k < x; ++exp){
        k *= 2;
    }
    return k == x ? pow2(exp) : pow2(exp + 1);
}

vector<pii> segtree(segtree_arr_size(100000), {-1, -1});

pii init_segtree(const vector<int>& nums, int node, int start, int end){
    if(start == end){
        return segtree[node] = {nums[start], nums[start]};
    } else{
        pii left = init_segtree(nums, 2*node, start, (start+end)/2);
        pii right = init_segtree(nums, 2*node+1, (start+end)/2+1, end);
        return segtree[node] = {
                                    min(left.first, right.first), 
                                    max(left.second, right.second)
                                };
    }
}

const int MAX_VALUE = 1000000001;
const int MIN_VALUE = 0;
pii minmax(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return {MAX_VALUE, MIN_VALUE};
    }
    if(left <= start && end <= right){
        return segtree[node];
    }
    int mid = (start + end) / 2;
    pii left_minmax = minmax(2*node, start, mid, left, right);
    pii right_minmax = minmax(2*node+1, mid+1, end, left, right);
    return { min(left_minmax.first, right_minmax.first), max(left_minmax.second, right_minmax.second)};
}

struct Node{
    int node;
    pii minmax;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    vector<pii> ranges(m);
    for(int i=0; i<n; ++i) cin >> nums[i];
    for(int i=0; i<m; ++i) cin >> ranges[i].first >> ranges[i].second;
    
    init_segtree(nums, 1, 0, n-1);
    for(const auto& r: ranges){
        pii result = minmax(1, 0, n-1, r.first-1, r.second-1);
        cout << result.first << " " << result.second << '\n';
    }

    return 0;
}