// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> X(n);
	for (auto& x : X) cin >> x;

	vector<int> Y(n);
	cout << 0 << " ";
	for (int i = 1; i < n; i++) {
		int P = X[i - 1] ^ Y[i - 1]; // prev
		Y[i] = (P | X[i]) ^ X[i];
		cout << Y[i] << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}