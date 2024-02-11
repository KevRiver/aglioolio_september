#include <iostream>
using namespace std;

int main(){

    int score; cin >> score;

    char grade;
    
    if(score < 60) grade = 'F';
    else if(score < 70) grade = 'D';
    else if(score < 80) grade = 'C';
    else if(score < 90) grade = 'B';
    else grade = 'A';

    cout << grade << '\n';

    return 0;
}