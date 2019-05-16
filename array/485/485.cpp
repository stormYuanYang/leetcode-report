#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
public:
    int findMaxConsecutiveOnes_old(vector<int>& nums) {
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
    // 同样的思路，但是代码实现更简单
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int LEN = nums.size();
        int maxCount = 0, tmpCount = 0;
        for (int i = 0; i < LEN; ++i) {
            if (nums[i]) {
                ++tmpCount;
            } else {
                if (maxCount < tmpCount) {
                    maxCount = tmpCount;
                }
                tmpCount = 0;
            }
        }
        // 要注意最后不是以0做连续1结束标记的情况
        if (maxCount < tmpCount) {
            maxCount = tmpCount;
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
