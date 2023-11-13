#include <iostream>
using namespace std;

int main(){ // WA
	/*假設輸入為單筆*/
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4; // 輸入前四項
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << " "; // 將前四項輸出
	if(a4 - a3 == a3 - a2){
		cout << a4 + (a3 - a2);
	}
	else{
		cout << a4 * (a3 / a2);
	}
	return 0;
}
