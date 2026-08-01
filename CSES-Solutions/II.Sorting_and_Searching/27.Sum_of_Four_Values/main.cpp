#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ot {
	long long value;
	int number;

	bool operator<(const ot& other)const {
		return value < other.value;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long x = 0;
	cin >> n >> x;
	vector <ot> array(n);
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		array[l] = ot(x, l);
	}
	sort(array.begin(), array.end());

	map <long long, pair<int, int>> list;
	for (int wall = 1; wall < n; wall++) {
		for (int j = wall + 1; j < n; j++) { // проверка правой части
			if (list.find(x - (array[wall].value + array[j].value)) != list.end()) {// нашли x - sum right 
				auto ans = *list.find(x - (array[wall].value + array[j].value));
				cout << ans.second.first + 1<< " " << ans.second.second + 1 << " " << array[wall].number + 1 << " " << array[j].number + 1;
				return 0;
			}
		}
		for (int j = 0; j < wall; j++) {
			list[array[j].value + array[wall].value] = pair(array[j].number, array[wall].number); 
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}