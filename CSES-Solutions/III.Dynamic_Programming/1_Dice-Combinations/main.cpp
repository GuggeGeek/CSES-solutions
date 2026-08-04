#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long const MOD = 1000000007;;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> array(n + 1, 0);
	array[0] = 1;
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= 6; j++) {
			if (l - j >= 0) array[l] = (array[l] + array[l - j]) % MOD;
		}
	}
	cout << array[n];
	return 0;
}