#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, string> idx_mbti;
unordered_map<string, int> mbti_idx;

const int INF = (int)21e9;
int dist[16][16];

int get_distance(const string& a, const string& b){
    int d=0;
    for(int i=0; i<4; ++i){
        if(a[i] != b[i]) ++d;
    }
    return d;
}

void solve(){
    int n; cin >> n;
    int group_size[16] = {0, };
    for(int i=0; i<n; ++i){
        string mbti; cin >> mbti;
        group_size[mbti_idx[mbti]]++;
    }
    vector<int> v;
    for(int i=0; i<16; ++i){
        if(group_size[i] == 0) continue;

        if(group_size[i] >= 3){
            cout << 0 << '\n';
            return;
        }

        int m = min(group_size[i], 2);
        for(int j=0; j<m; ++j){
            v.push_back(i);
        }
    }

    int len = v.size();
    int min_dist = INF;
    for(int i=0; i<len-2; ++i){
        for(int j=i+1; j<len-1; ++j){
            for(int k=j+1; k<len; ++k){
                int ab = dist[v[i]][v[j]];
                int bc = dist[v[j]][v[k]];
                int ca = dist[v[k]][v[i]];
                min_dist = min(min_dist, ab+bc+ca);
            }
        }
    }
    cout << min_dist << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<16; ++i){
        string mbti = "";
        mbti.push_back((i & (1 << 3)) == 0 ? 'E' : 'I');
        mbti.push_back((i & (1 << 2)) == 0 ? 'S' : 'N');
        mbti.push_back((i & (1 << 1)) == 0 ? 'F' : 'T');
        mbti.push_back((i & 1) == 0 ? 'J' : 'P');

        mbti_idx[mbti] = i;
        idx_mbti[i] = mbti;
    }

    for(int i=0; i<15; ++i){
        for(int j=i+1; j<16; ++j){
            string mbti0 = idx_mbti[i];
            string mbti1 = idx_mbti[j];
            int d = get_distance(mbti0, mbti1);
            dist[i][j] = dist[j][i] = d;
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}