#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m;
vector<int> books;

int main(){

    cin >> n >> m;
    books.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> books[i];
    }

    vector<int> left, right;
    for(int e: books){
        if(e < 0) left.push_back(e);
        else right.push_back(e);
    }

    sort(begin(left), end(left));
    sort(begin(right), end(right), greater<int>());

    vector<int> arr;
    for(int i = 0; i < left.size(); i += m){
        arr.push_back(left[i]);
    }
    
    for(int i = 0; i < right.size(); i += m){
        arr.push_back(right[i]);
    }
    
    int answer = 0;
    
    auto cmp = [](int l, int r){
        int ld = l < 0 ? -l : l;
        int rd = r < 0 ? -r : r;
        return ld < rd;
    };

    sort(begin(arr), end(arr), cmp);
    
    int prev = 0;
    for(int d : arr){
        answer += prev;
        if(d < 0) d = -d;
        answer += d;
        prev = d;
    }

    cout << answer << '\n';

    return 0;
}