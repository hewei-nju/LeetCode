#include <iostream>
#include <string>
using namespace std;

const string ZERO("00000000000000000000000000000000");

char AND(char a, char b)
{
    if (a == '0' || b == '0')
        return '0';
    return '1';
}

char OR(char a, char b)
{
    if (a == '1' || b == '1')
        return '1';
    return '0';
}

char NOT(char c)
{
    if (c == '0')
        return '1';
    return '0';
}

char XOR(char a, char b)
{
    if (a == b)
        return '0';
    return '1';
}

bool equalZero(const string& s)
{
    for (auto c : s)
        if (c != '0')
            return false;
    return true;
}

// 取反加一
string invertPlusOne(const string& s)
{
    string res(s);
    for (auto& c : res)
        c = NOT(c);
    char carry = '1';
    for (int i = s.size() - 1; i >= 0; --i) {
        char c = res[i];
        res[i] = XOR(c, carry);
        carry = AND(c, carry);
    }
    return res;
}

void leftShilt(string& s)
{
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1)
            s[i] = '0';
        else
            s[i] = s[i + 1];
    }
}

string booth(string src, const string& dest)
{
    if (equalZero(src) || equalZero(dest))
        return ZERO;
    string src_f = invertPlusOne(src);
    string R(2 * src.size(), '0');
    switch (dest[dest.size() - 1]) {
    case '0':
        break;
    case '1':
        R = add(R, src_f);
    }
    for ()
}

int main()
{
    cout << invertPlusOne("1111");
}