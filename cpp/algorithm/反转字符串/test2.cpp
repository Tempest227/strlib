class Solution {
public:
    string reverseStr(string s, int k) {
        int cur = 0;
        
        while(cur < s.size())
        {
            if (cur + k < s.size())
            {
                reverse(s.begin() + cur, s.begin() + cur + k);
            }
            else
            {
                reverse(s.begin() + cur, s.end());
            }
            cur += (2 * k);
        }
        return s;
    }
};