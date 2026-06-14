#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll get_lcm(ll a, ll b) { return a * b / gcd(a, b); }

void solve() {
	ll n;
	cin >> n;

	ll L = 1, res = 0;
	for (ll i = 2; i <= 50; i++) {
		ll L_next = get_lcm(L, i);
		res = (res + i * (n / L - n / L_next)) % MOD;
		L = L_next;
	}
	cout << res << "\n";
}
int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}