#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	long long n = 0;
	cin >> n;
	int zero = 0;
	for ( long long l = 5; l <= n; l = l * 5 ) {
		zero = zero + n / l;
	}

	cout << zero;
}