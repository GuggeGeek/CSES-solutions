#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, k = 0;
vector <long long> arrays;

bool chek(long long b) {
	long long current = 0, part = 1;
	for(auto now : arrays){
		if (now > b) return false;
		if ((current + now) > b) {
			part++;
			current = 0;
		}
		current += now;
	}
	return part <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		arrays.push_back(x);
	}

	long long maxi = (*max_element(arrays.begin(), arrays.end())) * n, ans = 0;
	for (long long b = maxi; b > 0; b /= 2) while (!chek(b + ans)) ans += b;
	cout << ans + 1;
	return 0;
}