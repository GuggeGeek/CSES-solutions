#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct movie {
	long long start;
	long long end;

	bool operator<(const movie& other)const {
		return end < other.end;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector <movie> array(n);
	for (int l = 0; l < n; l++) {
		long long a = 0, b = 0;
		cin >> a >> b;

		array[l] = movie(a, b);
	}
	sort(array.begin(), array.end());

	long long maxmov = 1, ends = array[0].end;
	for (int l = 1; l < n; l++) {
		if (array[l].start >= ends) {
			maxmov++;
			ends = array[l].end;
		}
	}

	cout << maxmov;

	return 0;
}