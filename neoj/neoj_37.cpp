#include <bits/stdc++.h>
using namespace std; // 37. queue 練習

const int N = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> qu;
	int t, x;
	cin >> t;
	while(t--){
		cin >> x;
		if(x == 1){
			cin >> x;
			qu.push(x);
		}
		else{
			if(qu.empty()){
				cout << "empty!\n";
			}
			else{
				cout << qu.front() << '\n';
				qu.pop();
			}
		}
	}
	return 0;
}