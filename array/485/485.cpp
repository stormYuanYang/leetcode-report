#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int LEN = nums.size();
        int maxCount = 0;
        int j = 0;
        for (int i = 0; i < LEN; ++i) {
            while (j < LEN && nums[j] == 0) {
                ++j;
            }
            if (j == LEN) {
                break;
            }
            if (nums[i] == 0) {
                if (maxCount < i - j) {
                    maxCount = i - j;
                }
                j = i + 1;
            } 
        }        
        if (nums[LEN-1]) {
            if (maxCount < LEN - j) {
                maxCount = LEN - j;
            }
        }
        return maxCount;
    }
};


#define yy
int main() {
#ifdef yy
    freopen("in.txt", "r", stdin);
#endif
    Solution sol;
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N >= 0);
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &nums[i]);
        }
        println(nums);
        println(sol.findMaxConsecutiveOnes(nums));
        println("~~~~");
    }
    return 0;
}
