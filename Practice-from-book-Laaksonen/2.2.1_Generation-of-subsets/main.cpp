#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
vi s;

void x(int k, int n) {
    if (k == n + 1) {
        cout << " { ";
        for (auto now : s) {
            cout << now << " ";
        }
        cout << "} ";
    }
    else {
        s.push_back(k);
        x(k + 1, n);
        s.pop_back();
        x(k + 1, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    x(1, n);
    return 0;
}