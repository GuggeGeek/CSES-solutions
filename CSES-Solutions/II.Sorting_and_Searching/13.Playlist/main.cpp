#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	map <long long, int> array;
	int left = 0, maxi = -1;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		if (array.contains(x)) { // песня уже была
			left = max(left, array[x] + 1);
		}
		array[x] = l;
		maxi = max(maxi, (l - left + 1));
	}

	cout << maxi;
	return 0;
}