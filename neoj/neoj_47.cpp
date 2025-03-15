#include <bits/stdc++.h>
using namespace std; // 47. 1d-kd-tree

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	int n, m;
	string str;
	cin >> n;
	for(; n--;){
		cin >> str >> m;
		if(str == "insert") s.insert(m);
		else if(str == "delete") s.erase(m);
		else{
			std::set<int>::iterator it = s.lower_bound(m);
			if(it != s.begin() && it != s.end()){
				std::set<int>::iterator it2 = it;
				--it2;
				if(abs((*it) - m) == abs(*it2 - m))
					cout << *it2 << ' ' << (*it) << '\n';
				else if(abs((*it) - m) > abs(*it2 - m))
					cout << *it2 << '\n';
				else
					cout << (*it) << '\n';
			}
			else if(it != s.begin())
				cout << *(--it) << '\n';
			else
				cout << *it << '\n';
		}
	}
	return 0;
}