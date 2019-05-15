#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

// 典型的贪心算法(为了尽可能多地获得利润，
// 就需要找到每一个局部最长的非降序子序列, 将每个局部最长的
// 子序列找到，那么最大利润就找到了)
//
// 更加简单的思考就是，能够获得利润就交易(当天是可以重复交易的,
// 就算当天不能重复交易，也可以这样求解最大利润)
// 根据贪心算法的思想，这样获得的利润肯定是最大的
class Solution {
public:
    int maxProfit_old(vector<int>& prices) {
        const int LEN = prices.size();
        if (LEN == 0) {
            return 0;
        }
        int maxProfit = 0; 
        int j = 0, i = 0;
        for (; i < LEN - 1; ++i) {
            if (prices[i] > prices[i+1]) {
                if (prices[j] < prices[i]) {// 避免递减时，加负数
                    maxProfit += prices[i] - prices[j];
                }
                // 改变j的值，指向下一个局部最长非降序子序列的第一个元素
                // 不是说j的值改变了，j就是子序列的第一个元素；而是在计算
                // 局部最大利润时，j表示的就是子序列的第一个元素
                j = i+1;
            }
        }
        // 需要考虑最后几天都是牛市的情况（数字一直增大）
        if (prices[j] < prices[i]) {
            maxProfit += prices[i] - prices[j];
        }
        return maxProfit;
    }

    // 同样利用贪心法的思想(但是代码编写更加简单)
    int maxProfit(vector<int>& prices) {
        const int LEN = prices.size();
        int maxProfit = 0;
        for (int i = 1; i < LEN; ++i) {
            if (prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
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
        vector<int> prices(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &prices[i]);
        }
        println(prices);
        println(sol.maxProfit(prices));
        println("~~~~");
    }
    return 0;
}
