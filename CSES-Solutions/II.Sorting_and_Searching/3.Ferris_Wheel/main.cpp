#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0; // n - кол-во детей 
	long long x = 0, ch = 0;; // максимальный вес детей в 1 кабинке
	cin >> n >> x;
	vector <long long> a(n);
	for (long long l = 0; l < n; l++) {
		cin >> a[l];
	}
	sort(a.begin(), a.end());
	long long r = 0, min = a[r], i = n - 1, max = a[i];
	while ( n > 0 ) {
		if (n == 1) {
			ch++;
			n--;
			break;
		}
		if (min + max > x) {
			ch++;
			i--;
			max = a[i];
			n--;
		}
		else {
			ch++;
			r++;
			i--;
			max = a[i];
			min = a[r];
			n = (n - 2);
		}
	}

	cout << ch;
	return 0;
}