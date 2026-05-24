#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
	// Helper function to add two large numbers represented as strings
	string addStrings(const string& num1, const string& num2) {
		string res = "";
		int i = num1.size() - 1, j = num2.size() - 1, carry = 0;

		while (i >= 0 || j >= 0 || carry) {
			int sum = carry;
			if (i >= 0) sum += num1[i--] - '0';
			if (j >= 0) sum += num2[j--] - '0';
			res.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	bool isValid(int i, int j, const string& num) {
		string num1 = num.substr(0, i);
		string num2 = num.substr(i, j);
		int k = i + j; // Pointer to track our position in the remaining string

		while (k < num.size()) {
			string next_num = addStrings(num1, num2);

			// Check if next_num matches the prefix of the remaining string at
			// index k
			if (num.compare(k, next_num.size(), next_num) != 0) {
				return false; // Mismatch found
			}

			k += next_num.size(); // Move the pointer forward

			// Shift numbers for the next iteration
			num1 = num2;
			num2 = next_num;
		}
		return k == num.size(); // True if we perfectly reached the end
	}

 public:
	bool isAdditiveNumber(string num) {
		int n = num.size();

		for (int i = 1; i <= n / 2; ++i) {
			// Leading zero check for the first number
			if (num[0] == '0' && i > 1) break;

			// The remaining string must be at least as long as max(i, j)
			for (int j = 1; n - i - j >= max(i, j); ++j) {
				// Leading zero check for the second number
				if (num[i] == '0' && j > 1) break;

				if (isValid(i, j, num)) {
					return true;
				}
			}
		}
		return false;
	}
};

class Solution_2 {
 private:
	bool f(string& fnum, string& snum, string& rem) {
		// leading zero not allowed
		if ((fnum.size() > 1 && fnum[0] == '0') ||
				(snum.size() > 1 && snum[0] == '0'))
			return false;

		// Check fnum + snum exist at start of 'rem'
		string sum = to_string(stol(fnum) + stol(snum));
		if (sum == rem) return true; // Yes, and EOString
		int ssz = sum.size();
		if (ssz > rem.size() || rem.substr(0, ssz) != sum)
			return false; // sum not found at start of 'rem'

		// Verify rest of the sequence
		rem = rem.substr(ssz);
		return f(snum, sum, rem);
	}

 public:
	bool isAdditiveNumber(string num) {
		int n = num.size();
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= (n - i) / 2; j++) {
				string fnum = num.substr(0, i);
				string snum = num.substr(i, j);
				string rem = num.substr(i + j);
				if (f(fnum, snum, rem)) return true;
			}
		}
		return false;
	}
};