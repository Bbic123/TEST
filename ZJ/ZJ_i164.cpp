#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
int t[N];
set<int> t1[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, ans;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> t[i];
	for(int i = 0; i < n; ++i){
		cin >> m;
		t1[m].insert(i);
	}
	for(int i = 0; i < n; ++i){
		ans = 0;
		if(!t1[t[i]].empty()){
			set<int>::iterator it = t1[t[i]].lower_bound(i);
			if(it == t1[t[i]].end()){
				ans = abs(*(--it) - i);
			}
			else if(it != t1[t[i]].begin()){
				a = *it;
				b = *(--it);
				ans = min(abs(a - i), abs(b - i));
			}
			else ans = abs(*(it) - i);
			cout << ans;
		}
		else cout << -1;
		cout << ' ';
	}
	return 0;
}