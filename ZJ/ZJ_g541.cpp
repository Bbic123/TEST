#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

struct Euclid_re{
	ll X, Y, GCD;
}re;

Euclid_re gcd(ll a, ll a1, ll a2, ll b, ll b1, ll b2){ // 用法：gcd(a, 1, 0, b, 0, 1);
	if(!b) return {a1, a2, a};
	ll c = a / b;
	return gcd(b, b1, b2, a - c * b, a1 - c * b1, a2 - c * b2);
}
// aX + bY = GCD

bool check(int d){
	if(d % re.GCD) return 0;
	if(d < n && d < m) return 0;
	ll x1 = re.X * (d / re.GCD), y1 = re.Y * (d / re.GCD);
	ll x2 = n / re.GCD, y2 = m / re.GCD;
	if(x1 < 0){
		y1 -= (-x1 / y2 + (-x1 % y2 > 0)) * x2;
		return y1 >= 0;
	}
	else if(y1 < 0){
		x1 -= (-y1 / x2 + (-y1 % x2 > 0)) * y2;
		return x1 >= 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, d;
	cin >> n >> m >> q;
	re = gcd(n, 1, 0, m, 0, 1);
	do{
		cin >> d;
		cout << (check(d) ? "YES\n" : "NO\n");
	}while(--q);
	return 0;
}