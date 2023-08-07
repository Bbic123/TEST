#include<iostream>
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y % 400 == 0){ // 浪琩琌400计
        cout << "a leap year\n";
    }
    else if(y % 4 == 0){ // 琌4计
        if(y % 100 != 0){
            cout << "a leap year\n"; // 璝ぃ100计秥
        }
        else{
            cout << "a normal year\n"; // 玥キ
        }
    }
    else{
        cout << "a normal year\n"; // 逞常琌キ
    }
}
