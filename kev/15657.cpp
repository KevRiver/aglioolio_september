#include <iostream>
#include <vector>
#include <functional>
#include <utility>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n);
    for(int i=0; i<n; ++i) cin >> nums[i];
    sort(begin(nums), end(nums));

    vector<vector<int>> seq;
    vector<int> tmp;

    function<void(int, int)> dfs = [&](int idx, int cnt){
        if(cnt == 0){
            vector<int> w(begin(tmp), end(tmp));
            seq.push_back(std::move(w));
            return;
        }

        for(int i=idx; i<n; ++i){
            for(int j=cnt; j>0; --j){
                for(int k=0; k<j; ++k) tmp.push_back(nums[i]);
                dfs(i+1, cnt-j);
                for(int k=0; k<j; ++k) tmp.pop_back();
            }
        }
    };

    dfs(0, m);

    for(const vector<int>& row: seq){
        for(int e: row) cout << e << " ";
        cout << '\n';
    }

    return 0;
}