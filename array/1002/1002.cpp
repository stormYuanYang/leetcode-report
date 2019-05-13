#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "../../include/tools.h"
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        size_t index = 0;    
        for (int i = 1; i < A.size(); ++i) {
            if (A[index].size() > A[i].size()) {
                index = i;
            }
        }
        unordered_map<char, int> hashtable; 
        for (auto it = A[index].cbegin(); it != A[index].cend(); ++it) {
            if (hashtable.count(*it) == 0) {
                hashtable[*it] = 1;
            } else {
                ++hashtable[*it];
            }
        }
        unordered_map<char, int> tmpHT; 
        for (auto it = hashtable.cbegin(); it != hashtable.cend(); ++it) {
            tmpHT[it->first] = 0;
        }
        for (int i = 0; i < A.size(); ++i) {
            for (auto it = A[i].cbegin(); it != A[i].cend(); ++it) {
                if (hashtable.count(*it) > 0) {
                    ++tmpHT[*it];
                }
            }
            for (auto it = hashtable.begin(); it != hashtable.end(); ++it) {
                if (tmpHT.count(it->first) > 0) {
                    if (it->second > tmpHT[it->first]) {
                        it->second = tmpHT[it->first];
                    }
                } else {
                    it->second = 0;
                }
            }

            for (auto it = tmpHT.begin(); it != tmpHT.end(); ++it) {
                tmpHT[it->first] = 0;
            }
        }

        vector<string> ret;
        for (auto it = hashtable.cbegin(); it != hashtable.cend(); ++it) {
            for (int i = 0; i < it->second; ++i)  {
                string tmpStr("a");
                tmpStr[0] = it->first;
                ret.push_back(tmpStr);
            }
        }
        return ret;
    }
};

//#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    vector<string> A = {"cool","lock","cook"};
    vector<string> ret = sol.commonChars(A);
    println(ret);
    return 0;
}
