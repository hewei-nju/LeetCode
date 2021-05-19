class Solution {
public:
    bool validPalindrome(string s) {

        // error in algorithm
        // int i = 0, j = static_cast<int>(s.size()) - 1;
        // bool use = false;
        // while (i != j && i < j) {
        //     if (s[i] == s[j])
        //         ++i, --j;
        //     else if(use) 
        //         return false;    
        //     else {
        //         use = true;
        //         if (s[i+1] == s[j])
        //             i += 2, --j;
        //         else if (s[i] == s[j - 1])
        //             ++i, j -= 2;
        //         else
        //             return false;
        //     }
        // }
        // return true;
        return valid(s, 0, static_cast<int>(s.size()) - 1, false);
    }

    bool valid(string& s, int i, int j, bool use) {
        if (i != j && i < j) {
            if (s[i] == s[j])
                return valid(s, i + 1, j - 1, use);
            else if (use)
                return false;
            else {
                if (s[i + 1] == s[j] || s[i] == s[j - 1])

                    return valid(s, i + 2, j - 1, !use) || valid(s, i + 1, j - 2, !use);
                return false;
            }
        }
        return true;
    }
};