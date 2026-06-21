#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void move( int n , int from , int to ,int aux ) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	move(n - 1, from, aux, to);
	cout << from << " " << to << "\n";
	move(n - 1, aux, to, from);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	cout << pow(2 , n) - 1 << "\n";
	move(n , 1 , 3 , 2 );
	

	return 0;
}