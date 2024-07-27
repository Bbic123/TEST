#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, x, y, z, w, n, m;
	string s;
	cin >> t;
	while(t--){
		cin >> x >> y >> z >> w >> n >> m;
		getline(cin, s);
		getline(cin, s);
		if(s.size() == 0){
			cout << m << "g\n";
			continue;
		}
		stringstream ss(s);
		bool f = true;
		int a, b = 0;
		while(ss >> a){
			m -= b * n;
			if(m <= 0){
				f = false;
				break;
			}
			if(a == 0)
				continue;
			else if(a == 1)
				m += x;
			else if(a == 2)
				m += y;
			else if(a == 3)
				m -= z;
			else if(a == 4){
				m -= w;
				b++;
			}
			if(m <= 0){
				f = false;
				break;
			}
		}
		if(f)
			cout << m << "g\n";
		else
			cout << "bye~Rabbit\n";
	}
	return 0;
}