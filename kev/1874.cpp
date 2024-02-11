#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> seq;
    for(int i=0; i<n; ++i){
        int num; cin >> num;
        seq.push_back(num);
    }

    stack<int> s;
    int idx = 0;
    vector<char> op_seq;
    for(int num=1; num <= n; ++num){
        while(!s.empty() && (s.top() == seq[idx])){
            s.pop();
            op_seq.push_back('-');
            ++idx;
        }
        s.push(num);
        op_seq.push_back('+');
    }
    while(!s.empty() && (s.top() == seq[idx])){
        s.pop();
        op_seq.push_back('-');
        ++idx;
    }
    
    if(idx < seq.size()) cout << "NO" << '\n';
    else{
        for(char op: op_seq) cout << op << '\n';
    }

    return 0;
}