#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "../../include/tools.h"
using namespace std;


class Solution {
public:
    // 划分的思想 使用两个指针进行操作
    // 注意，题目要求保持非零元素的相对位置不变
    // 所以两个指针只能从同一方向移动
    // 注意为满足题目中的操作次数尽可能的少
    // 这里不用交换 直接对后面的元素赋0
    void moveZeroes(vector<int>& nums) {
        const int len = nums.size();
        int j = -1;
        for (int i = 0; i < len; ++i) {
            if (nums[i]) {
                nums[++j] = nums[i];
            }
        }
        while (++j < len) {
            nums[j] = 0;
        }
    }
};


int main() {
#define yy
#ifdef yy
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    Solution sol;
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N >= 0);
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &nums[i]);
        }
        sol.moveZeroes(nums);
        println(nums);
        println("~~~~");
    }
    return 0;
}
