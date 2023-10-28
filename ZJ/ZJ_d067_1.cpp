#include<iostream>
using namespace std;

int main(){
	int y;
	cin >> y;
	if(y % 400 == 0){ // 檢查是否為400的倍數
		cout << "a leap year\n";
	}
	else if(y % 4 == 0){ // 是否為4的倍數
		if(y % 100 != 0){
			cout << "a leap year\n"; // 若不為100的倍數即位閏年
		}
		else{
			cout << "a normal year\n"; // 否則為平年
		}
	}
	else{
		cout << "a normal year\n"; // 剩下都是平年
	}
	return 0;
}