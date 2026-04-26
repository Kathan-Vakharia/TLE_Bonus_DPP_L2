class Solution {
 public:
	int kthGrammar(int n, int k) {
		if (n == 1) return 0;

		int entries = 1 << (n - 1);
		if (k <= entries / 2)
			return kthGrammar(n - 1, k);
		else
			return !kthGrammar(n - 1, k - entries / 2);
	}
};