#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int LEN = A.size();
        if (LEN == 1) {
            return true;
        }
        bool increase = false, decrease = false;
        for (int i = 1; i < LEN; ++i) {
            if (A[i-1] < A[i]) {//局部递增
                increase = true;
            } else if (A[i-1] > A[i]){// 局部递减
                decrease = true;
            }
            // else{}A[i-1]==A[i]不用管，默认就是单调的
            
            // 同时有递增和递减子序列
            // 那么A不可能是单调序列
            if (increase && decrease) {
                return false;
            }
        }
        return true;
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
        vector<int> A(N);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        println(sol.isMonotonic(A));
    }
    return 0;
}
