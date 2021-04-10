// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
# include <iostream>
using namespace std;
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int maxLen = 0;
    int tmpLen = 0;
    int i = 0;
    for ( ; i <= 31; ++i) {
        if ((N & 0x80000000) != 0) {
            N <<= 1;
            ++i;
            break;
        } else {
            N <<= 1;
        }
    }
    while (i <= 31) {
        ++i;
        if ((N & 0x80000000) == 0) {
            tmpLen += 1;
        } else {
            if (tmpLen > maxLen) {
                maxLen = tmpLen;
            }
            tmpLen = 0;
        }
        N <<= 1;
    }
    return maxLen;
}


int main()
{
    cout << solution(1041) << endl;
    return 0;
}