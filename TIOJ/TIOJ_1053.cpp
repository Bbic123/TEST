#include <iostream>
using namespace std;

int main(){
	int p, q;
	cin >> p >> q;
	if(p > q)
		swap(p, q);
	if(q % p)
		cout << "N\n";
	else
		cout << "Y\n";
	return 0;
}