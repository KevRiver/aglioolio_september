#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// next permutation 시간초과
// dfs 시간초과
// next permutation 직접 구현?

using namespace std;

int dfs(int cnt, int idx, vector<int>& kinds, const vector<int>& seq){
    if(cnt == 0){
        int ret = 1;
        for(int k: kinds){
            ret *= seq[k];
        }
        return ret;
    }

    if(idx == seq.size()){
        return  0;
    }

    int sum = 0;
    for(int i=idx; i<seq.size(); ++i){
        
        // i번째 종류의 옷을 입는다.
        kinds.push_back(i);
        sum += dfs(cnt - 1, i + 1, kinds, seq);
        kinds.pop_back();
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    
    unordered_map<string, int> kind_idx;
    vector<int> seq;
    
    for(int r=0; r<t; ++r){
        
        kind_idx.clear();
        seq.clear();

        int n; cin >> n;

        for(int i=0; i<n; ++i){
            string name; cin >> name;
            string kind; cin >> kind;
            
            auto look = kind_idx.find(kind);
            if(look != kind_idx.end()){
                int idx = look->second;
                seq[idx]++;
            } else{
                seq.push_back(1);
                kind_idx[kind] = seq.size() - 1;
            }
        }

        int size = seq.size();
        int answer = 1;
        for(int cnt: seq){
            answer *= (cnt + 1);
        }
        --answer; // 전부다 입지 않는 경우의 수를 뺀다.
        cout << answer << '\n';
    }

    return 0;
}