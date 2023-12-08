#include <bits/stdc++.h>
using namespace std; // abc170_A - Five Variables

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	for(int i = 1; i <= 5; ++i){
		cin >> n;
		if(!n) cout << i <<'\n';
	}
	return 0;
}