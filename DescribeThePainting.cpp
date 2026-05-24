#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
 public:
	vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
		int n = segments.size();

		// Map stores the net color change at each coordinate.
		// map automatically keeps the coordinates sorted.
		map<ll, ll> mp;
		for (int i = 0; i < n; i++) {
			ll s = segments[i][0], e = segments[i][1], c = segments[i][2];
			mp[s] += c; // Color sum increases at the start
			mp[e] -= c; // Color sum decreases at the end
		}

		vector<vector<ll>> res;
		ll cur_sum = 0;
		int prev_x = -1;

		// Sweep the line from left to right across all event coordinates
		for (auto [cur_x, acc] : mp) {
			// If there was an active color sum during the previous stretch, record
			// the interval
			if (cur_sum > 0) {
				res.push_back({prev_x, cur_x, cur_sum});
			}

			// Update the running total with the net change at this current stop
			cur_sum += acc;
			// Move the marker forward for the next iteration
			prev_x = cur_x;
		}

		return res;
	}
};