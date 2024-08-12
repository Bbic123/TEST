#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	map<string, int> mp;
	while(cin >> n){
		mp.clear();
		string s;
		for(int i = 0, cnt = 0; i < n; ++i){
			cin >> s;
			if(mp[s]){
				cout << "Old! " << mp[s] << '\n';
			}
			else{
				cout << "New! " << ++cnt << '\n';
				mp[s] = cnt;
			}
		}
	}
	return 0;
}