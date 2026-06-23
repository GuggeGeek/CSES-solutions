#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> alf(26 , 0);
string glob = "";
long long var = 0;
void box1( int ch) {
	if (glob.size() == ch) {
		var++;
		return;
	}
	else {
		for (int l = 0; l < 26 ; l++) {
			if (alf[l] > 0) {
				glob += char(l + 'a');
				alf[l]--;
				box1(ch);
				glob.pop_back();
				alf[l]++;
			}
		}
	}
}
void box2(int ch) {
	if (glob.size() == ch) {
		cout << glob << "\n";
		return;
	}
	else {
		for (int l = 0; l < 26; l++) {
			if (alf[l] > 0) {
				glob += char(l + 'a');
				alf[l]--;
				box2(ch);
				glob.pop_back();
				alf[l]++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	string n = "";
	cin >> n;
	int ch = n.size();
	for (char now : n) alf[now - 'a']++;
	box1(ch);
	cout << var << "\n";
	box2(ch);

	return 0;
}