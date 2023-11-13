#include <iostream>
using namespace std;

int main(){ // while
	int t, a1, a2, a3, a4;
	cin >> t;
	while(t != 0){
		cin >> a1 >> a2 >> a3 >> a4; // 輸入前四項
		cout << a1 << " " << a2 << " " << a3 << " " << a4 << " "; // 將前四項輸出
		if(a4 - a3 == a3 - a2){
			cout << a4 + (a3 - a2);
		}
		else{
			cout << a4 * (a3 / a2);
		}
		cout << "\n"; // 不要忘了換行
		t -= 1;
	}
	return 0;
}
