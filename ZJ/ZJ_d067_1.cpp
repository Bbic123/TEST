#include<iostream>
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y % 400 == 0){ // �ˬd�O�_��400������
        cout << "a leap year\n";
    }
    else if(y % 4 == 0){ // �O�_��4������
        if(y % 100 != 0){
            cout << "a leap year\n"; // �Y����100�����ƧY��|�~
        }
        else{
            cout << "a normal year\n"; // �_�h�����~
        }
    }
    else{
        cout << "a normal year\n"; // �ѤU���O���~
    }
}
