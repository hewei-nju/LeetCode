class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size - 1;
        int carry = 1;
        int num = digits[i];
        for ( ; i >= 0; --i) {
            if (digits[i] + carry != 10) {
                digits[i] += carry;
                carry = 0;
                break;
            } else {
                digits[i] = (digits[i] + carry) % 10;
                carry = 1;
            }
        }
        if (num == 9 && carry == 1) {
            digits.push_back(0);
            digits[i + 1] = 1;
        }
        return digits;
    }
};

