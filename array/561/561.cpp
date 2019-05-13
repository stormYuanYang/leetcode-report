#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
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
        int sum = sol.arrayPairSum(A);
        println(sum);
    }
    return 0;
}
