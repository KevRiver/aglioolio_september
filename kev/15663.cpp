#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>
using namespace std;

int n, m;

unordered_set<string> used_seq;

int main(){
    cin >> n >> m;
    vector<int> nums;
    for(int i=0; i<n; ++i){
        int num; cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    
    int size = nums.size();
    vector<bool> used(n, false);

    function<void(int, string)> dfs = [&](int cnt, string seq){
        
        if(cnt == m){
            if(used_seq.find(seq) == used_seq.end()){
                used_seq.insert(seq);
                cout << seq << '\n';
            }
            return;
        }
        
        for(int i=0; i<n; ++i){
            if(used[i]) continue;
            used[i] = true;

            string next_seq = seq;
            next_seq.append(to_string(nums[i]) + " ");
            
            dfs(cnt + 1, next_seq);
            used[i] = false;
        }
    };
    
    dfs(0, "");
    
    return 0;
}