#include <bits/stdc++.h>

using namespace std;

double calc_adj_area(int h1, int h2){
    double rect = h1 < h2 ? h1 : h2;
    double tri = h1 < h2 ? (double)(h2-h1)/2 : (double)(h1-h2)/2;
    return rect + tri;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    
    vector<double> areas;
    while(k > 1){
        int y = (k%2 == 0) ? k/2 : 3*k+1;
        areas.push_back(calc_adj_area(k, y));
        k = y;
    }
    
    int n = areas.size();
    vector<double> prefix(n + 1);
    
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        prefix[i] = prefix[i-1] + areas[i-1];
    }
    
    vector<double> answer;
    for(const auto& r: ranges){
        int s = r[0];
        int e = n + r[1];
        
        double result;
        if(s > e) result = -1.0;
        else result = prefix[e] - prefix[s];
        
        answer.push_back(result);
    }
    
    return answer;
}