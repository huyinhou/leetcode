
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#endif

class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        itera = A.begin();
        itere = A.end();
        if (itera != itere) {
            count = *itera;
        }
    }
    
    int next(int n) {
        if (itera == itere) {
            return -1;
        }
        while (count < n) {
            n -= count;
            itera += 2;
            if (itera == itere) {
                return -1;
            }
            count = *itera;
        }
        count -= n;
        return *(itera + 1);
    }

private:
    vector<int>::iterator itera;
    vector<int>::iterator itere;
    int count;
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    vector<int> v1 = {3,8,0,9,2,5};
    RLEIterator it1(v1);
    assert(it1.next(2) == 8);
    assert(it1.next(1) == 8);
    assert(it1.next(1) == 5);
    assert(it1.next(2) == -1);

    vector<int> v2 = {635,606,576,391,370,981,36,21,961,
    185,124,210,801,937,22,426,101,260,221,647,350,180,
    504,39,101,989,199,358,732,839,919,169,673,967,58,676,
    846,342,250,597,442,174,472,410,569,509,311,357,838,251};
    RLEIterator it2(v2);
    cout<<it2.next(5039)<<std::endl;
    it2.next(62);
    cout<<it2.next(364000);
    cout<<it2.next(3640);
    it2.next(3640);
    it2.next(3640);
    it2.next(3640);
    return 0;
}
#endif
