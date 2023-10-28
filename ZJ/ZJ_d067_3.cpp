#include<iostream>
using namespace std;

int main(){
	int y;
	cin >> y;
	if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)){ // 再合併
		cout << "a leap year\n";
	}
	else{
		cout << "a normal year\n";
	}
	return 0;
}