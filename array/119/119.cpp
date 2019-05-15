#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "../../include/tools.h"
using namespace std;

// 如果仅仅是为了耍AC的时间的话，可以现将所有结果求出来
// getRow()直接返回即可 时间复杂读O(1) 空间复杂度O(k2)
class Solution {
public:
    // 和直接求整个杨辉三角的时间复杂读一样都是O(k2);
    // 空间复杂度O(k) 比起直接求整个杨辉三角的空间复杂度O(k2)
    // 少很多
    vector<int> getRow(int rowIndex) {
        const size_t LEN = rowIndex + 1;
        vector<int> ret(LEN);
        for (int i = 0; i < LEN; ++i) {
            ret[i] = 1;
        }
        for (int i = 2; i < LEN; ++i) {
            // 注意这里需要逆序处理
            // 顺序处理会数据错乱
            for (int j = i - 1; j > 0; --j) {
                ret[j] += ret[j-1];
            }
        }
        return ret;
    }
};

#define yy
int main() {
#ifdef yy
    freopen("out.txt", "w", stdout);
#endif
    Solution sol;
    int N = 33;
    for (int i = 1; i <= N; ++i) {
        println(sol.getRow(i));
    }
    return 0;
}
