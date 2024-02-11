#include <iostream>
#include <queue>
using namespace std;

// 현재 맨 앞 문서의 중요도를 검사한다
// 1. 큐에 뒤에 현재 문서보다 중요도가 높은 문서가 존재하면 현재 문서를 맨 뒤로 재배치 -> priority queue
// 2. 현재 문서가 가장 중요도가 높으면 출력
// 현재 문서가 어디에 있는지가 입력으로 주어진다. 초기 n번째에 위치한 문서가 최종 몇번째로 출력되는지 구한다.
// 위치를 추적해야한다, 중요도는 어떻게? N이 매우 작음, 매번 중요도 검사를 O(N)에 실행해도 문제 없음

struct Doc{
    int initial_pos;
    int priority;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        queue<Doc> q;
        priority_queue<int> priorities;
        for(int i=0; i<n; ++i){
            int p; cin >> p;
            q.push({i, p});
            priorities.push(p);
        }
        
        int cnt = 0;
        while(true){
            Doc cur = q.front();
            q.pop();

            if(cur.priority == priorities.top()){
                ++cnt;
                priorities.pop();
                if(cur.initial_pos == m){
                    cout << cnt << '\n';
                    break;
                }
            } else{
                q.push(cur);
            }
        }
        
    }

    return 0;
}