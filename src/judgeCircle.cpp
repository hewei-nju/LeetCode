class Solution {
public:
    bool judgeCircle(string moves) {
        array<int, 2> arr{0,0};
        for (auto &s: moves)
            if (s == 'U')
                arr[0] += 1;
            else if (s == 'D')
                arr[0] -= 1;
            else if (s == 'L')
                arr[1] += 1;
            else
                arr[1] -= 1;
        return arr[0] == 0 && arr[1] == 0;
    }
};