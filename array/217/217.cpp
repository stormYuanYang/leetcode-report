#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "../../include/tools.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        const int LEN = nums.size();
        unordered_map<int, int> hashtable;
        for (int i = 0; i < LEN; ++i) {
            if (hashtable.count(nums[i]) == 0) {
                hashtable[nums[i]] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
#define yy
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N >= 0);
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        println(sol.containsDuplicate(A));
    }
    return 0;
}
/*
static const auto closeIOSync = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
*/
