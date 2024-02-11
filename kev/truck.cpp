#include <bits/stdc++.h>

using namespace std;

struct Entry{
    int w;
    int pass;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    const auto& v = truck_weights;
    int cur_weight = 0;
    queue<Entry> q;
    
    
    function<bool(int)> can_truck_go = [&](int w) -> bool{
        
        if(q.size() >= bridge_length)
            return false;
        
        if(w + cur_weight > weight)
            return false;
        
        return true;
    };
    
    int t = 1;
    cur_weight = v[0];
    q.push({v[0], t + bridge_length});
    
    for(int i = 1; i < v.size(); ++i){
        cout << t << '\n';
        ++t; // 2
        
        while(!can_truck_go(v[i])){
            const auto& front = q.front();
            
            t = front.pass;
            
            cur_weight -= front.w;
            q.pop();
        }
        
        cur_weight += v[i];
        q.push({v[i], t + bridge_length});
    }
    
    int answer = q.back().pass;
    return answer;
}