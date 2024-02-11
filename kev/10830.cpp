#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const int MOD = 1'000;

vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> ret(n, vector<int>(n));
    for(int r=0; r<n; ++r){
        for(int c=0; c<n; ++c){
            int x = 0;
            for(int i=0; i<n; ++i){
                x += (a[r][i]*b[i][c]) % MOD;
                x %= MOD;
            }
            ret[r][c] = x;
        }
    }
    return ret;
}

vector<vector<int>> f(vector<vector<int>> mat, ll exp){
    if(exp == 1) return mat;
    if(exp % 2 == 1) return mul(mat, f(mat, exp-1));
    vector<vector<int>> p = f(mat, exp/2);
    return mul(p, p);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ll B; cin >> B;
    vector<vector<int>> mat(N, vector<int>(N));
    for(int r=0; r<N; ++r){
        for(int c=0; c<N; ++c){
            int n; cin >> n;
            mat[r][c] = n % MOD;
        }
    }
    vector<vector<int>> result = f(mat, B);
    for(int r=0; r<N; ++r){
        for(int c=0; c<N; ++c){
            cout << result[r][c] << " ";
        }
        cout << '\n';
    }

    return 0;
}