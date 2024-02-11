#include <iostream>
#include <queue>
#include <string>
using namespace std;

int double_up(int num) {return num*2 % 10000;}
int subtract_one(int num) {return num-1 < 0 ? 9999 : num-1;}
int push_left(int num) {return (num%1000)*10 + num/1000;}
int push_right(int num) {return (num%10)*1000 + (num/10);}

int (*f_dslr[4])(int) = {double_up, subtract_one, push_left, push_right};
const string dslr = "DSLR";

struct Entry{
    int num;
    string cmds;
};

string solve(int a, const int b){
    
    bool used[10000] = {false, };
    function<string(int, const int)> bfs = [&](int cur, const int target){
        
        string answer = "";
        
        queue<Entry> q;
        q.push({cur, ""});
        used[cur] = true;
        
        while(!q.empty()){
            Entry cur = q.front();
            q.pop();

            if(cur.num == target){
                answer = cur.cmds;
                break;
            }

            for(int k=0; k<4; ++k){
                int next_num = f_dslr[k](cur.num);
                
                if(used[next_num]) continue;
                used[next_num] = true;
                
                string next_cmds = cur.cmds;
                next_cmds.push_back(dslr[k]);
                
                q.push({next_num, next_cmds});        
            }
        }
        return answer;
    };

    return bfs(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    for(int r=0; r<t; ++r){
        int a; cin >> a;
        int b; cin >> b;
        string answer = solve(a, b);
        cout << answer << '\n';
    }

    return 0;
}