#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> even_idx, odd_idx;

	// 1. Split elements by index parity (using 0-based indexing)
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) {
			even_idx.push_back(a[i]);
		} else {
			odd_idx.push_back(a[i]);
		}
	}

	// 2. Sort the separate parities
	sort(even_idx.begin(), even_idx.end());
	sort(odd_idx.begin(), odd_idx.end());

	// 3. Merge them back together
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a[i] = even_idx[i / 2];
		} else {
			a[i] = odd_idx[i / 2];
		}
	}

	// 4. Check if the combined array is sorted
	if (is_sorted(a.begin(), a.end())) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}