#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, m;
	cin >> n >> k >> m;

	// Store pairs of {remainder, original_value}
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr[i] = {val % m, val};
	}

	// Sort by remainder. Elements with the same remainder will end up adjacent.
	sort(arr.begin(), arr.end());

	// Linear scan to count adjacent identical remainders
	int count = 1;
	for (int i = 0; i < n; i++) {
		// If it matches the previous remainder, increment count
		if (i > 0 && arr[i].first == arr[i - 1].first) {
			count++;
		} else {
			count = 1; // Reset for a new remainder group
		}

		// If we hit our target k, print the last k elements and exit
		if (count == k) {
			cout << "Yes\n";
			for (int j = i - k + 1; j <= i; j++) {
				cout << arr[j].second << " ";
			}
			cout << "\n";
			return 0;
		}
	}

	cout << "No\n";
	return 0;
}