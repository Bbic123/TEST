#include<iostream>
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y % 400 == 0){
        cout << "a leap year\n";
    }
    else if(y % 4 == 0 && y % 100 != 0){ // �Nif�X��
        cout << "a leap year\n";
    }
    else{
        cout << "a normal year\n";
    }
}
