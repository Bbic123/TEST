#include <bits/stdc++.h>
using namespace std; // 512. 霖澤黑森林

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> sk;
	int n, a, f = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a;
		if(a > 0) sk.push(a);
		else{
			if(!sk.empty() && sk.top() == -a) sk.pop();
			else{
				f = 1;
				break;
			}
		}
	}
	if(f || !sk.empty()) cout << "lose light light\n";
	else cout << "weed\n";
	return 0;
}