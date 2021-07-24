class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.find(' ');

        while(right != string::npos)
        {
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right = s.find(' ', left);
        }
        reverse(s.begin() + left, s.end());

        return s;
    }
};