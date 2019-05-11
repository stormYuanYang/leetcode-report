/*
 * 学过quick sort的话就应该知道 quick sort中有划分元素的处理
 * 只不过quick sort是根据大小划分，同样的，这里亦可使用划分的思想：
 * 以奇偶性划分
 */
#include <cstdio>
#include <vector>
#include <cassert>
#include "../include/tools.h"
using namespace std;

class Solution {
public:
    inline bool isEvent(int n) {
        return (n & 1) == 0;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret = A;
        // 两头找
        for (int i = 0, j = ret.size() - 1; i < j; ++i, --j) {
            while (i < j && isEvent(ret[i])) {//从左往右找到第一个奇数
                ++i;
            }
            while (j > i && !isEvent(ret[j])) {//从右往左找到第一个偶数
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(ret[i], ret[j]);
        }
        return ret;
    }
};

#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    int n;
    while (scanf("%d", &n) != EOF) {
        print(n);
        assert(n > 0);
        vector<int> A(n); for (int i = 0; i < n; ++i) { scanf("%d", &A[i]);
        }
        vector<int> ret = sol.sortArrayByParity(A);

        for (int i = 0; i < ret.size(); ++i) {
            printf("%d ", ret[i]);
        }
        printf("\n");
    }
    return 0;
}
