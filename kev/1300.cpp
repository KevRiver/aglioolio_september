#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int k; cin >> k;
    
    int low = 1, high = k + 1;
    int answer;
    while(low < high){
        int mid = (low + high) / 2;
        // mid 보다 작거나 같은 수는 몇개일까
        int cnt = 0;
        for(int i=1; i<=n; ++i){
            cnt += min(n, mid/i);
        }

        if(cnt >= k){
            answer = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
    

    return 0;
}