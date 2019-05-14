#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        assert(nums.size()>0 && nums[0].size() > 0 && r > 0 && c > 0);
        if (nums.size() * nums[0].size() != r * c) {
            return nums;
        }
        vector<vector<int>> ret(r);
        for (int i = 0; i < r; ++i) {
            ret[i].resize(c);
        }
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                ret[a][b] = nums[i][j];
                if (++b == c) {
                    b = 0;
                    ++a;
                }
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
    int N, M, newN, newM;
    while (scanf("%d%d%d%d", &N, &M, &newN, &newM) != EOF) {
        assert(N > 0 && M > 0);
        vector<vector<int>> A(N);
        for (int i = 0; i < N; ++i) {
            A[i].resize(M);
            for (int j = 0; j < M; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        vector<vector<int>> ret = sol.matrixReshape(A, newN, newM); 
        println(ret);
    }
    return 0;
}
