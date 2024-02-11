#include <iostream>
#include <vector>
#include <string>
using namespace std;

string remove_bombs(const string& str, const string& bomb){
    
    int n = str.size();
    int m = bomb.size();
    char trigger = bomb.back();
    
    string ret = "";
    for(int i=0; i<n; ++i){
        
        ret.push_back(str[i]);
        int len = ret.size();
        
        if(str[i] != trigger) continue;
        if(len < m) continue;

        if(ret.substr(len - m, m) == bomb){
            for(int k=0; k<m; ++k) ret.pop_back();
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    string bomb; cin >> bomb;
    const int len = bomb.size();
    
    string after_removal = remove_bombs(str, bomb);

    if(after_removal.empty()) cout << "FRULA" << '\n';
    else cout << after_removal << '\n';

    return 0;
}