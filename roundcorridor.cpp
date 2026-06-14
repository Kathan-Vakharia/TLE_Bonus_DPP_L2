#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, m, q;
	cin >> n >> m >> q;
	ll g = gcd(n, m);

	while (q--) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		ll start_id = (sx == 1) ? (sy - 1) / (n / g) : (sy - 1) / (m / g);
		ll end_id = (ex == 1) ? (ey - 1) / (n / g) : (ey - 1) / (m / g);

		if (start_id == end_id)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}
