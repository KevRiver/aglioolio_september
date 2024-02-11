#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; // 사람 수 N, 파티 수 M
    cin >> N >> M;
    int K; // 진실을 아는 사람의 수
    cin >> K;
    unordered_set<int> knowers;
    for(int i=0; i<K; ++i){
        int k; cin >> k;
        knowers.insert(k);
    }

    vector<vector<int>> parties(M);
    for(int i=0; i<M; ++i){
        int P; cin >> P;
        for(int j=0; j<P; ++j){
            int p; cin >> p;
            parties[i].push_back(p);
        }
    }

    // 루프마다 진실을 말해야 하는 파티를 찾으면서, 거짓말 할 수 있는 파티의 수를 센다
    // 진실을 말한 파티에 참가한 사람들을 knowers에 추가한다.
    // 추가된 사람이 있으면 루프를 다시 돌면서 거짓말 할 수 있는 파티의 수를 센다.
    // 추가된 사람이 없으면 루프를 종료한다. 마지막으로 기록한 거짓말 한 파티 수가 조건을 만족하는 최대 파티 수가 된다.
    int answer = 0;
    int prev, cur;
    prev = cur = K;
    do{
        prev = cur;
        vector<int> v;
        int cnt = 0;
        for(int i=0; i<M; ++i){
            vector<int>& participants = parties[i];
            bool lied = true;
            for(int p: participants){
                if(knowers.find(p) != knowers.end()){
                    v.push_back(i);
                    lied = false; 
                    break;
                }
            }
            if(lied) ++cnt;
        }
        answer = cnt;

        for(int i: v){
            vector<int>& participants = parties[i];
            for(int p: participants){
                knowers.insert(p);
            }
        }
        cur = knowers.size();
    }while(cur > prev);

    cout << answer << '\n';

    return 0;
}