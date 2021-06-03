class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> seen;
        for (auto email: emails) {
            string str;
            bool plus = false;
            bool AT = false;
            for (int i = 0; i < email.size(); ++i) {
                if (AT) {
                    str += email[i];
                } else if (plus) {
                    if (email[i] == '@') {
                        str += email[i];
                        AT = true;
                    }
                } else if (email[i] == '+') {
                    plus = true;
                } else if (email[i] != '.') {
                    if (email[i] == '@')
                        AT = true;
                    str += email[i];
                }
            }
            cout << str << endl;
            if (seen.find(str) == seen.end())
                seen.insert(str);
        }

        return seen.size();
    }
};