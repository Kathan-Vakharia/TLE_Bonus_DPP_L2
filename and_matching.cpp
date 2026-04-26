#include <bits/stdc++.h>

using namespace std;

/**
 * Problem Logic:
 * We need to pair numbers from 0 to n-1 such that sum of (a_i & b_i) = k.
 * Since n is a power of 2, the maximum possible value is n-1.
 * * General strategy:
 * Pair x with its complement (n-1-x) to get 0.
 * Then swap elements to isolate k.
 */

// Helper function to find the complement of x relative to n
int get_complement(int x, int n) { return x ^ (n - 1); }

void solve() {
	int n, k;
	cin >> n >> k;

	// We need n/2 pairs
	vector<pair<int, int>> pairs(n / 2);

	// Default case: pair everything with its complement so the AND sum is 0
	for (int i = 0; i < n / 2; i++) {
		pairs[i] = {i, get_complement(i, n)};
	}

	// Case 1: 0 < k < n-1
	// We want to achieve an AND sum of k.
	// We pair (k, n-1) to get k, and (0, complement of k) to get 0.
	if (k > 0 && k < n - 1) {
		int comp_k = get_complement(k, n);
		int idx = min(k, comp_k);

		// Adjust the pairs that involved k and n-1
		pairs[0] = {0, comp_k};
		pairs[idx] = {k, n - 1};
	}

	// Case 2: k == n-1
	// It's impossible to get k = n-1 when n = 4.
	if (k == n - 1) {
		if (n == 4) {
			cout << -1 << "\n";
			return;
		}

		/* For k = n-1, we use a specific shuffle:
			 (n-1, n-2), (n-3, 1), (0, 2)
			 The sum: (n-1 & n-2) + (n-3 & 1) + (0 & 2)
			 Example for n=8: (7&6)=6, (5&1)=1, (0&2)=0 -> Total 7.
		*/
		pairs[0] = {0, 2};
		pairs[1] = {1, n - 3};
		pairs[2] = {n - 2, n - 1};
	}

	// Case 3: k == 0
	// The default loop already handles this.

	for (const auto& p : pairs) {
		cout << p.first << " " << p.second << "\n";
	}
}

int main() {
	// Standard I/O optimization
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) solve();

	return 0;
}