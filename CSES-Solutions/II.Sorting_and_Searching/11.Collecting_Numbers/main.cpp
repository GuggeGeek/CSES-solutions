#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct quantity {
	int value;
	int number;

	bool operator<(const quantity& other)const {
		return value < other.value;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector <quantity> array(n);
	for (int l = 0; l < n; l++) {
		int x = 0;
		cin >> x;
		array[l] = quantity(x, l);
	}
	sort(array.begin(), array.end());

	int round = 1, last_round = -1;
	for (auto now : array) {
		if (now.number < last_round) round++;
		last_round = now.number;
	}
	cout << round;

	return 0;
}