#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
public:
    // 这个题也可以用动态规划的思想来完成
    int maxProfit(vector<int>& prices) {
        const int LEN = prices.size();
        if (LEN < 2) {// 交易的结果肯定是0
            return 0;
        }
        int buy = prices[0], maxProfit = 0;
        for (int i = 1; i < LEN; ++i) {
            if (buy < prices[i]) {
                if (maxProfit < prices[i] - buy) {
                    maxProfit = prices[i] - buy;
                }
            }
            else {
                buy = prices[i];// 在更低点买入
            }
        }
        return maxProfit;
    }
};


#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
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
