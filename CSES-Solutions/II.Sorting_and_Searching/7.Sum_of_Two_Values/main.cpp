#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct number {
	long long value;
	long long place;

	bool operator<(const number& other)const {
		return value < other.value;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long x = 0;
	cin >> n >> x;
	vector <number> array(n);

	for (int l = 0; l < n; l++) {
		long long values = 0;
		cin >> values;
		array[l] = number(values, l + 1);
	}

	sort(array.begin(), array.end());
	
	for (auto now : array) {
		long long a = 0, b = n - 1 ,need = x - now.value;
		while (a <= b) {
			long long k = (a + b) / 2;
			if (array[k].value > need) b = k - 1;
			else if (array[k].value < need) a = k + 1;
			else {
				if (now.place != array[k].place) {
					cout << now.place << " " << array[k].place;
					return 0;
				}
				break;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}