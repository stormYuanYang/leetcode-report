#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
public:
    // 注意，当n较大时，序列[0,n]的和可能会溢出
    // 但是没关系，这里依然能够正确求得丢失的那个数字
    // 只是在做题时，要想到是否会溢出的问题
    // 虽然得到的结果在数学意义上是错误的
    // 但是其计算是可逆的，从某种意义上来说，又可以说是正确的
    // 对于int32来说，所有的计算都限制在32位之内；
    // 虽然最终的结果值可能不是我们想要的，但是计算过程是可逆的
    int missingNumber_old(vector<int>& nums) { 
        // 根据高斯求和公式求得下标的和
        const int LEN = nums.size();
        int sum = LEN * (LEN+1) / 2;
        for (int i = 0; i < LEN; ++i) {
            sum -= nums[i];
        }
        return sum;
    }
    
    // 通过位运算
    // 两个相同的数字进行异或运算，结果必定是0
    // 一个数和0异或还是它本身
    int missingNumber(vector<int>& nums) {
        const int LEN = nums.size();
        if (LEN == 0) {
            throw;
        }
        int x = 0;
        for (int i = 0; i < LEN; ++i) {
            x ^= nums[i] ^ i;
        }
        x ^= LEN;
        return x;
    }
};

int main() {
#define yy
#ifdef yy
    freopen("in.txt", "r", stdin);
#endif
    Solution sol;
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N >= 0);
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        println(sol.missingNumber(A));
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
