#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dp[200001];
const int mod = 10007;

int mod_sum(int a, int b, int mod) {return ((a % mod) + (b % mod)) % mod;}
int mod_product(int a, int b, int mod) {return ((a % mod) * (b % mod)) % mod;}

int main(){
    int n = 10, k = 3;
    dp[1] = 1;
    for(int x = 2; x <= n; ++x){
        set<pair<int, int>> used;

        if(x == k) {
            dp[x] = 1;
            continue;
        }

        if(x % 2 == 0){
            int p = x / 2;
            int q = x / 2;
            if(used.find({p, q}) == used.end()){
                dp[x] = mod_sum(dp[x], mod_product(dp[p], dp[q], mod), mod);
            }
        }

        if(x > k){
            int p = k;
            int q = x - k;
            
            if(p > q){
                int tmp = p;
                p = q;
                q = tmp;
            }

            if(used.find({p, q}) == used.end())
                dp[x] = mod_sum(dp[x], mod_product(dp[p], dp[q], mod), mod);
        }

        if(x > k && x % 2 != 0){
            int p = (x - k) / 2;
            int q = p + k;
            if(used.find({p, q}) == used.end())
                dp[x] = mod_sum(dp[x], mod_product(dp[p], dp[q], mod), mod);
        }
    }
    
    cout << dp[n] << '\n';

    return 0;
}