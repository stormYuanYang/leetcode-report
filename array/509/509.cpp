#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "../../include/tools.h"
using namespace std;

class Solution {
public:
    // 以空间换时间 先将斐波那契数缓存起来
    // 函数fib直接查询即可
    int A[31];
    Solution() {
        A[0] = 0;
        A[1] = 1;
        for (int i = 2; i < 31; ++i) {
            A[i] = A[i-1] + A[i-2];
        }
    }

    int fib(int N) {
        assert(N >= 0 && N <= 30);
        return A[N];
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 31; ++i) {
        println(sol.fib(i));
    }
    return 0;
}
