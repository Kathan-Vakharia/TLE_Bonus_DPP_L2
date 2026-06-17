#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	// Impossible to form the sum if the number of elements exceeds the sum itself
	if (n > m) {
		cout << "NO\n";
		return;
	}

	if (n % 2 == 0) {
		if (m % 2 == 0) {
			cout << "YES\n";
			for (int i = 0; i < n - 2; i++) {
				cout << 1 << " ";
			}

			int remainder = (m - n + 2) / 2;
			cout << remainder << " " << remainder << "\n";
		} else {
			cout << "NO\n";
		}
	} else {
		cout << "YES\n";
		for (int i = 0; i < n - 1; i++) {
			cout << 1 << " ";
		}
		cout << (m - n + 1) << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}