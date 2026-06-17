#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << "\n";
		return;
	}

	// largest power of 2 less than N
	int msb = 31 - __builtin_clz(N);
	int P = 1 << msb;

	// Candidate 1: Final incomplete block
	int cand1 = N - P + 1;

	// Candidate 2: The largest complete block right before P [P/2, P-1]
	int cand2 = P / 2;

	cout << max(cand1, cand2) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}