#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // 21. 陸行鳥大賽車

int ans[N], pre[N], nxt[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		ans[i] = i;
		pre[i] = i - 1;
		if(i + 1 <= n) nxt[i] = i + 1;
	}
	cin >> m;
	int T, x, st = 1;
	while(m--){
		cin >> T >> x;
		if(T){
			if(pre[x] == st){
				pre[pre[x]] = x;
				nxt[pre[x]] = nxt[x];
				pre[nxt[x]] = pre[x];
				nxt[x] = pre[x];
				st = x;
				pre[x] = 0;
			}
			else if(x != st){
				nxt[pre[x]] = nxt[x];
				pre[nxt[x]] = pre[x];
				nxt[x] = pre[x];
				int ha = pre[pre[x]];
				nxt[ha] = x;
				pre[pre[x]] = x;
				pre[x] = ha;
			}
		}
		else{
			if(x == st){
				st = nxt[x];
				pre[nxt[x]] = 0;
				nxt[x] = pre[x] = 0;
			}
			else{
				nxt[pre[x]] = nxt[x];
				pre[nxt[x]] = pre[x];
				nxt[x] = pre[x] = 0;
			}
		}
	}
	cout << st;
	st = nxt[st];
	while(st) cout << ' ' << st, st = nxt[st];
	cout << '\n';
	return 0;
}