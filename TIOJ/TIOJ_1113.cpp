#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while(cin >> s){
		sort(s.begin(), s.end());
		do{
			cout << s << '\n';
		}while(next_permutation(s.begin(), s.end()));
		cout << '\n';
	}
	return 0;
}
