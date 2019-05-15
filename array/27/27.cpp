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
    // 实际上就是一次划分操作
    // 将所有等于val的元素都移动到数组最右端
    // 时间复杂度O(n) 空间复杂度O(1)
    // 比起用双指针从两端找，可能会多执行整数加法和交换操作
    // 但是实现起来非常简单
    int removeElement_1(vector<int>& nums, int val) {
        const size_t LEN = nums.size();
        int j = -1;
        for (int i = 0; i < LEN; ++i) {
            if (nums[i] != val) {
                if (i != ++j) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return j + 1;
    }
    // 理论上，左右两端查找效率更高一些（都是O(n)）
    // 但是需要处理一些细节，才能正确获取新的长度
    // 代码要更复杂一些
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] != val) {
                ++i;
            }
            while (i < j && nums[j] == val) {
                --j;
            }
            if (i == j) {
                break;
            }
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
        if (nums[i] == val) {
            return i;
        } 
        else {
            return i+1;
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
    int N, val;
    while (scanf("%d%d", &N, &val) != EOF) {
        assert(N >= 0);
        vector<int> nums;
        for (int i = 0; i < N; ++i) {
            int tmp;
            scanf("%d", &tmp);
            nums.push_back(tmp);
        }
        int n = sol.removeElement(nums, val);
        println(n);
        println("~~");
        println(nums);
        println("~~~~~~~~~~~~~~~~~~~~~");
    }
    return 0;
}
