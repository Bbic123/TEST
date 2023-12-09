#include <bits/stdc++.h>
using namespace std;

struct Euclid_re{
	int X, Y, GCD;
};

Euclid_re gcd(int a, int a1, int a2, int b, int b1, int b2){ // 用法：gcd(a, 1, 0, b, 0, 1);
	if(!b) return {a1, a2, a};
	int c = a / b;
	return gcd(b, b1, b2, a - c * b, a1 - c * b1, a2 - c * b2);
}
// aX + bY = GCD

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	while(cin >> a >> b){
		Euclid_re ans = gcd(a, 1, 0, b, 0, 1);
		cout << ans.X << ' ' << ans.Y << ' ' << ans.GCD << '\n';
	}
	return 0;
}