#include <iostream>
#include <vector>

using namespace std;

int root[100];
int depth[100];

int find_root(int node){
    if(root[node] == node) return node;
    else return root[node] = find_root(root[node]);
}

bool merge(int a, int b){
    int i = find_root(a);
    int j = find_root(b);
    
    if(i == j) return false;
    
    if(depth[i] < depth[j]){
        root[i] = j;
    }
    else{
        root[j] = i;
    }
    
    if(depth[i] == depth[j]) depth[i]++;
    
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    // union find
    for(int i = 0; i < n; ++i){
        root[i] = i;
        depth[i] = 1;
    }
    
    sort(begin(costs), end(costs), 
         [](const vector<int>& l, const vector<int>& r){
             return l[2] < r[2];
         });
    
    int answer = 0;
    for(const auto& info: costs){
        int a = info[0];
        int b = info[1];
        int c = info[2];
        
        if(merge(a, b)) answer += c;
    }

    return answer;
}

int main(){

    cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << '\n';

    return 0;
}