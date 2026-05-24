#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
class Solution {
 private:
	map<vector<int>, int> memo;
	// hypothesis: returns minimum total cost to satisfy needs
	int f(vi& price, vvi& offers, vi& needs) {
		if (memo.contains(needs)) return memo[needs];

		// Base cost: buying everything individually at regular price
		int cost = inner_product(price.begin(), price.end(), needs.begin(), 0);

		// try to apply every possible offer
		for (vi& offer : offers) {
			bool is_valid = true;
			for (int j = 0; j < needs.size(); j++) {
				if (offer[j] > needs[j]) {
					is_valid = false;
					break;
				}
			}

			if (is_valid) {
				// Apply the offer (modify needs in-place)
				for (int j = 0; j < needs.size(); j++) {
					needs[j] -= offer[j];
				}

				// offer.back() contains the price of the special offer
				cost = min(cost, offer.back() + f(price, offers, needs));

				// Backtrack: revert the needs array to its previous state
				for (int j = 0; j < needs.size(); j++) {
					needs[j] += offer[j];
				}
			}
		}

		return memo[needs] = cost;
	}

 public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
										 vector<int>& needs) {
		return f(price, special, needs);
	}
};