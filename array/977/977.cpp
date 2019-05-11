#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& A) {
        int begin = 0, end = A.size() - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (A[mid] >= 0) {
                if (mid == 0) {
                    return -1;
                }
                if (A[mid-1] < 0) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        if (A.empty()) {
            return ret;
        }
        int index = binarySearch(A);
        if (index == -1) {
            if (A[0] < 0) {
                for (int i = A.size()-1; i >= 0; --i) {
                    ret[A.size() - 1 - i] = A[i] * A[i];
                }
            } else {
                for (int i = 0; i < A.size(); ++i) {
                    ret[i] = A[i] * A[i]; }
            }
        } else {
            int i = index - 1, j = index, k = 0;
            while (k < A.size()) {
                if (i < 0) {
                    ret[k] = A[j]*A[j];
                    ++j;
                } else if (j == A.size()) {
                    ret[k] = A[i]*A[i];
                    --i;
                } else {
                    if (A[i]*A[i] < A[j]*A[j]) {
                        ret[k] = A[i]*A[i];
                        --i;
                    } else {
                        ret[k] = A[j]*A[j];
                        ++j;
                    }
                } 
                ++k;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> A = {-1, 1};
    vector<int> ret = sol.sortedSquares(A);
    for (int i = 0; i < ret.size(); ++i) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}
