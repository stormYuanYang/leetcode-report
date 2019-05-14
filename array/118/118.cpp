#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ret(numRows);
            if (numRows == 0) {
                return ret;
            }
            ret[0].resize(1);
            ret[0][0] = 1;
            for (int i = 1; i < numRows; ++i) {
                ret[i].resize(i+1);
                for (int j = 0; j < i+1; ++j) {
                    if (j == 0) {
                        ret[i][j] = ret[i-1][j];
                    } else if (j == ret[i-1].size()){
                        ret[i][j] = ret[i-1][j-1];
                    } else {
                        ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
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
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N > 0);
        vector<vector<int>> ret = sol.generate(N); 
        println(ret);
    }
    return 0;
}
