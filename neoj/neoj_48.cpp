#include <bits/stdc++.h>
using namespace std; // 48. 二元搜尋樹

const int N = 1e5 + 5;
int up[N], low[N];

void search_(int x){
	if(low[x] != -1)
		search_(low[x]);
	if(up[x] != -1)
		search_(up[x]);
	cout << x << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, top;
	cin >> n;
	fill(up, up + N, -1);
	fill(low, low + N, -1);
	cin >> top;
	int now;
	for(int i = 1; i < n; i++){
		now = top;
		cin >> m;
		while(1){
			if(m > now){
				if(up[now] == -1){
					up[now] = m;
					break;
				}
				else{
					now = up[now];
				}
			}
			else if(m < now){
				if(low[now] == -1){
					low[now] = m;
					break;
				}
				else{
					now = low[now];
				}
			}
		}
	}
	search_(top);
	return 0;
}