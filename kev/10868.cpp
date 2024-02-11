#include <iostream>
#include <vector>
using namespace std;

struct SimpleLogResult{
    int z;
    bool is_decimal_exist;
};

SimpleLogResult log(int base, int n){
    if(n == 1) return {0, false};
    int y=0;
    int x=1;
    while(x < n){
        x *= base;
        ++y;
    }
    if(x == n) return {y, false};
    else return {y-1, true};
}

int ceil(const SimpleLogResult& res){
    return res.is_decimal_exist ? res.z + 1 : res.z;
}

int pow(int base, int exp){
    if(exp == 0) return 1;
    int res = 1;
    while(exp--) res*=base;
    return res;
}
int segtree_size(int n){
    int h = ceil(log(2, n));
    return pow(2, h+1);
}
const int MAX_VALUE = (int)1e9 + 1;
vector<int> segtree(segtree_size(100000), MAX_VALUE);

int init_segtree(const vector<int>& nums, int node, int start, int end){
    if(start == end){
        return segtree[node] = nums[start];
    } else{
        int mid = (start+end)/2;
        int left = init_segtree(nums, 2*node, start, mid);
        int right = init_segtree(nums, 2*node+1, mid+1, end);
        return segtree[node] = min(left, right);
    }
}

int min_in_range(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return MAX_VALUE;
    }
    if(left <= start && end <= right){
        return segtree[node];
    }
    int mid = (start+end)/2;
    int left_min = min_in_range(2*node, start, mid, left, right);
    int right_min = min_in_range(2*node+1, mid+1, end, left, right);
    return min(left_min, right_min);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n); for(int i=0; i<n; ++i) cin >> nums[i];
    vector<pair<int, int>> ranges(m); for(int i=0; i<m; ++i) cin >> ranges[i].first >> ranges[i].second;
    
    init_segtree(nums, 1, 0, n-1);
    for(auto range: ranges){
        int l = range.first - 1;
        int r = range.second - 1;
        cout << min_in_range(1, 0, n-1, l, r) << '\n';
    }

    return 0;
}