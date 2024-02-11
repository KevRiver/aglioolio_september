#include <iostream>
#include <vector>

using namespace std;


void quick_sort(vector<int>& v, int l, int r){
    if(l >= r) return;

    int pivot = v[l];
    int low = l + 1, high = r;
    do{
        if(v[low] > pivot && v[high] < pivot){
            int tmp = v[low];
            v[low] = v[high];
            v[high] = tmp;
        }
        if(v[low] <= pivot) ++low;
        if(v[high] >= pivot) --high;
    }while(low <= high);
    
    int tmp = v[high];
    v[high] = v[l];
    v[l] = tmp;

    quick_sort(v, l, high - 1);
    quick_sort(v, high + 1, r);
}

void sort(vector<int>& v){
    int l = 0, r = v.size() - 1;
    quick_sort(v, l, r);
}

int main(){
    
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    sort(arr);

    for(int e: arr){
        cout << e << " ";
    }
    cout << '\n';


    return 0;
}