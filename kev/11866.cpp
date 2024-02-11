#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string string_join(const vector<int>& seq, const char* delimeter){
    string str;
    for(int i=0; i<seq.size(); ++i){
        str.append(to_string(seq[i]));
        if(i != seq.size() - 1){
            str.append(delimeter);
        }
    }
    return str;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int k; cin >> k;
    queue<int> q;
    for(int i=1; i<=n; ++i) q.push(i);
    vector<int> seq;
    while(!q.empty()){
        for(int i=0; i<k-1; ++i){
            q.push(q.front());
            q.pop();
        }
        seq.push_back(q.front());
        q.pop();
    }

    cout << "<" << string_join(seq, ", ") << ">" << '\n';
    
    return 0;
}