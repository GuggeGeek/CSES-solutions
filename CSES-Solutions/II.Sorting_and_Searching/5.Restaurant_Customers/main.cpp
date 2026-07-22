#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct times{
	long long  time;
	int type;

	bool operator<(const times& other)const {
		return time < other.time;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	
	vector<times> array;

	for (int l = 0; l < n; l++) {
		long long a = 0, b = 0;
		cin >> a >> b;

		array.push_back(times(a, 1));
		array.push_back(times(b, -1));
	}

	sort(array.begin(), array.end());

	long long current = 0;
	long long maxi = 0;
	for (auto now : array) {
		if (now.type == 1) current++;
		else current--;
		maxi = max(maxi, current);
	}

	cout << maxi;
	return 0;
}