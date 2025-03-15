#include <bits/stdc++.h>
using namespace std; // 25. 一天遊戲只能一小時

const int N = 1e6 + 5;

int nxt[N], n_front[105], n_back[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x, y;
	cin >> n >> m;
	string s;
	for(int i = 0; i < m; ++i){
		cin >> s;
		if(s == "ADD"){
			cin >> x >> y;
			if(n_front[x] == 0){
				n_front[x] = y;
				n_back[x] = y;
			}
			else{
				nxt[n_back[x]] = y;
				n_back[x] = y;
			}
		}
		else if(s == "LEAVE"){
			cin >> x;
			if(n_front[x] == 0){
				cout << "queue " << x << " is empty!\n";
				continue;
			}
			if(nxt[n_front[x]] != 0){
				n_front[x] = nxt[n_front[x]];
			}
			else{
				n_front[x] = n_back[x] = 0;
			}
		}
		else if(s == "JOIN"){
			cin >> x >> y;
			if(n_front[y] == 0){
				n_front[y] = n_front[x];
				n_back[y] = n_back[x];
				n_back[x] = n_front[x] = 0;
			}
			else{
				if(n_front[x] != 0){
					nxt[n_back[y]] = n_front[x];
					n_back[y] = n_back[x];
					n_back[x] = n_front[x] = 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		if(n_front[i] == 0){
			cout << "queue " << i << ": empty\n";
		}
		else{
			cout << "queue " << i << ": ";
			cout << n_front[i];
			if(nxt[n_front[i]] != 0){
				int now = n_front[i];
				while(now != n_back[i]){
					now = nxt[now];
					cout << ' ' << now;
				}
			}
			cout << '\n';
		}
	}
	return 0;
}