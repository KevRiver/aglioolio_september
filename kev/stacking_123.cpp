#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define veci vector<int>

struct ChildrenNodes{
    int idx = 0;
    veci children;
    int next(){
        return children[idx];
    }
    void next_idx(){
        int n = children.size();
        idx = (idx + 1) % n;
    }
    void prev_idx(){
        int n = children.size();
        idx = (idx - 1 + n) % n;
    }
};

unordered_map<int, ChildrenNodes> graph;

bool is_identical(const veci& l, const veci& r){
    if(l.size() != r.size()) return false;
    for(int i = 0; i < l.size(); ++i){
        if(l[i] != r[i]) return false;
    }
    return true;
}

int drop(int cur, veci& node_record){    
    auto look = graph.find(cur);

    if(look == graph.end()){
        return cur;
    }
    
    node_record.push_back(cur);
    ChildrenNodes& node = look->second;
    int next = node.next();
    return drop(next, node_record);
};
    
int get_leaf(veci& node_record){
    int leaf = drop(1, node_record);
    return leaf;
};

veci answer;
void dfs(veci& state, const veci& target, veci& path){
    if(!answer.empty() && (answer.size() < path.size())){
        cout << "early return\n" << '\n';
        return;
    }
        
    if(is_identical(state, target)){
        if(answer.empty() || path.size() < answer.size() || path < answer){
            answer.clear();
            for(int e : path){
                answer.push_back(e);
            }
        }
        return;
    }

    // get next leaf
    veci node_record;
    int leaf = get_leaf(node_record);

    for(int n = 3; n > 0; --n){
        if(state[leaf-1] + n > target[leaf-1]){
            continue;
        }

        state[leaf-1] += n;
        path.push_back(n);
        for(int node: node_record){
            ChildrenNodes& k = graph[node];
            k.next_idx();
        }

        dfs(state, target, path);

        for(int node: node_record){
            ChildrenNodes& k = graph[node];
            k.prev_idx();
        }
        path.pop_back();
        state[leaf-1] -= n;
    }
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
        
    for(auto& edge: edges){
        int p = edge[0];
        int ch = edge[1];
        graph[p].children.push_back(ch);
    }
    
    for(auto& entry: graph){
        veci& children = entry.second.children;
        sort(begin(children), end(children));
    }
    
    veci state(target.size(), 0);
    veci path;
    dfs(state, target, path);
    
    if(answer.empty()) answer.push_back(-1);
    return answer;
}

int main(){

    return 0;
}