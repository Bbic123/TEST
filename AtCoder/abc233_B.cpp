#include <bits/stdc++.h>
using namespace std; // abc233_B - A Reverse

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int l, r;
	cin >> l >> r >> s;
	reverse(&s[l - 1], &s[r]);
	cout << s << '\n';
	return 0;
}
