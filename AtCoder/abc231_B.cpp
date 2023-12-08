#include <bits/stdc++.h>
using namespace std; // abc231_B - Election

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, ans;
	map<string, int> mp;
	int t, mx = 0;
	cin >> t;
	while(t--){
		cin >> s;
		++mp[s];
	}
	for(auto i : mp){
		if(i.second > mx){
			mx = i.second;
			ans = i.first;
		}
	}
	cout << ans << '\n';
	return 0;
}
