#include <bits/stdc++.h>

using namespace std;

/**
 * Problem: AGAGA XOOORRR (Codeforces 1516B)
 * * Logic:
 * 1. If the total XOR sum of the array is 0, we can split it into two
 * equal halves (since A ^ B = 0 implies A = B).
 * 2. If the total XOR sum (X) is not 0, we must be able to split the
 * array into at least 3 segments where each segment XORs to X.
 */

void solve() {
	int n;
	cin >> n;

	vector<long long> arr(n);
	long long total_xor = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total_xor ^= arr[i];
	}

	// Case 1: Total XOR sum is 0.
	// If the entire array XORs to 0, it means we can split it at some point
	// such that the left side equals the right side (A ^ A = 0).
	if (total_xor == 0) {
		cout << "YES" << endl;
		return;
	}

	// Case 2: Total XOR sum is non-zero.
	// We try to partition the array into 3 or more segments that each
	// match the total_xor value.
	long long current_segment_xor = 0;
	int segment_count = 0;

	for (int i = 0; i < n; i++) {
		current_segment_xor ^= arr[i];

		if (current_segment_xor == total_xor) {
			segment_count++;
			current_segment_xor = 0;
		}
	}

	// If we found at least 3 segments, the condition is satisfied.
	if (segment_count >= 3) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
} //* T: O(t*n) = O(3e4)
//* S: O(1)