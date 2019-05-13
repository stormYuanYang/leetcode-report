#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"
using namespace std;

class Solution {
public:
    inline bool isOdd(int n) {
        return n & 1;
    }
    //vector<int> sortArrayByParityII(vector<int>& A) {
    //    //assert((A.size() & 1) == 0);
    //    vector<int> ret = A;
    //    size_t len = ret.size();
    //    for (int i = 0, j = 1; i < len && j < len; i += 2, j += 2) {
    //        while (i < len && !isOdd(A[i])) {
    //            i += 2;
    //        }
    //        while (j < len && isOdd(A[j])) {
    //            j += 2;
    //        }
    //        if (i >= len || j >= len) {
    //            break;
    //        }
    //        swap(ret[i], ret[j]);
    //    }
    //    return ret;
    //}

    vector<int> sortArrayByParityII(vector<int>& A) {
        //assert((A.size() & 1) == 0);
        size_t len = A.size();
        vector<int> ret(len);
        int eventIndex = 0, oddIndex = 1;
        for (int i = 0; i < len; ++i) {
            if (isOdd(A[i])) {
                ret[oddIndex] = A[i];
                oddIndex += 2;
            } else {
                ret[eventIndex] = A[i];
                eventIndex += 2;
            }
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
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N > 0);
        vector<int>A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        vector<int> ret = sol.sortArrayByParityII(A);
        println(ret);
    }
    return 0;
}
