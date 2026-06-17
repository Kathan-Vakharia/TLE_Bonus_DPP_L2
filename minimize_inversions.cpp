#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> P(n);
		for (int i = 0; i < n; i++) cin >> P[i].first;
		for (int i = 0; i < n; i++) cin >> P[i].second;

		// Sort pairs by A[i] — B[i] tags along automatically
		sort(P.begin(), P.end());

		for (auto& [a, b] : P) cout << a << " ";
		cout << "\n";
		for (auto& [a, b] : P) cout << b << " ";
		cout << "\n";
	}
	return 0;
}