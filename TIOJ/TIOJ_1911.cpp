#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	bool f = false;
	multiset<int> ms;
	while(cin >> n, n){
		if(!ms.empty() && n == -1){
			if(f) cout << ' ';
			f = true;
			cout << *ms.begin();
			ms.erase(ms.begin());
		}
		else if(!ms.empty() && n == -2){
			if(f) cout << ' ';
			f = true;
			cout << *(--ms.end());
			ms.erase(--ms.end());
		}
		else if(n != -1 && n != -2) ms.insert(n);
	}
	cout << '\n';
	return 0;
}
