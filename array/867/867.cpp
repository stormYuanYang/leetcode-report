#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        //assert(A.size() > 0 && A[0].size() > 0);
        vector<vector<int>> ret(A[0].size());
        for (int i = 0; i < ret.size(); ++i) {
            ret[i].resize(A.size());
            for (int j = 0; j < A.size(); ++j) {
                ret[i][j] = A[j][i];
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
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        assert(N > 0 && M > 0);
        vector<vector<int>> A(N);
        for (int i = 0; i < N; ++i) {
            A[i].resize(M);
            for (int j = 0; j < M; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        vector<vector<int>> ret = sol.transpose(A); 
        println(ret);
    }
    return 0;
}
