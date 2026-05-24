#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long b, c, d;
	cin >> b >> c >> d;

	long long a = 0;

	for (int i = 0; i < 61; i++) {
		int bit_b = (b >> i) & 1;
		int bit_c = (c >> i) & 1;
		int bit_d = (d >> i) & 1;

		bool found = false;
		// Try setting the i-th bit of a to either 0 or 1
		for (int bit_a : {0, 1}) {
			if (((bit_a | bit_b) - (bit_a & bit_c)) == bit_d) {
				if (bit_a) a |= (1LL << i);
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "-1" << endl;
			return;
		}
	}
	cout << a << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) solve();

	return 0;
}