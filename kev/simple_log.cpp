#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief 간단한 로그 계산, 자연수 밑과 진수만 다루며 항상 n >= base 상황을 가정한다.
 * 
 * @param base 로그의 밑
 * @param n 로그의 진수, 1이거나 base값보다 커야한다.
 * @return pair<int, bool> int: 로그값의 정수부, bool: 로그값에 소수점이 발생하면 true 그렇지 않으면 false를 반환한다
 */
pair<int, bool> simple_log(int base, int n){
    if(n == 1) return {0, false};
    int y = 0;
    int x = 1; // base^0 = 1
    while(x < n) {
        x *= base;
        ++y;
    }
    return x == n ? make_pair(y, false) : make_pair(y-1, true);
}

int main(){
    auto result = simple_log(2, 8);
    assert(result.first == 3 && result.second == false);
    cout << "passed test #1" << '\n';

    result = simple_log(2, 100000);
    assert(result.first == 16 && result.second == true);
    cout << "passed test #2" << '\n';

    return 0;
}