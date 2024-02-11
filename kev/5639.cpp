#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void print_postorder(const vector<int>& preorder, int start, int end){
    if(start == end) return;
    int m = start + 1;
    for(;preorder[m] < preorder[start] && m < end; ++m);
    print_postorder(preorder, start + 1, m);
    print_postorder(preorder, m, end);
    cout << preorder[start] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> preorder;
    int n;
    while(cin >> n)
        preorder.push_back(n);
    int size = preorder.size();
    print_postorder(preorder, 0, size);
    
    return 0;
}