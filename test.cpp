#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;


bool strendswith(const char *str, const char *end)
{
    assert(str != NULL && end != NULL);
    int len1 = 0;
    int len2 = 0;
    while (*str++) { ++len1; }
    while (*end++) { ++len2; }
    cout << *str << " " << *end << endl;
    if (len1 < len2) return false;
    while (len2-- > 0) {
        --str;
        --end;
        cout << *str << " " << *end << endl;
        if (*str != *end)
            return false;
        
    }
    return true;
}

int main()
{
    if (strendswith("11abcd", "*.bcd"))
        cout << "TRUE" << endl;
    else 
        cout << "FALSE" << endl;
}
