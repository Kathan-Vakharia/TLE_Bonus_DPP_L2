#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int M = 1e9 + 7;

// O(1) helper function to decode the character
inline int get_val(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
	if (c >= 'a' && c <= 'z') return c - 'a' + 36;
	if (c == '-') return 62;
	if (c == '_') return 63;
	return 0;
}

int main() {
	string s;
	cin >> s;

	ll ans = 1;
	for (char ch : s) {
		int x = get_val(ch);

		// A 6-bit number has a maximum of 6 bits.
		// Unset (zero) bits = 6 - (number of set bits)
		int zeroes = 6 - __builtin_popcount(x);

		for (int b = 0; b < zeroes; b++) {
			ans = (ans * 3) % M;
		}
	}

	cout << ans << '\n';

	return 0;
}