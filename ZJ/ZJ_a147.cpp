#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n, n){
		for(int i = 1; i < n; ++i)
			if(i % 7)
				cout << i << ' ';
		cout << '\n';
	}
	return 0;
}