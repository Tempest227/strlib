class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start < end)
        {
            if ((s[start] <= 'z' && s[start] >= 'a' || s[start] <= 'Z' && s[start] >= 'A')
            && (s[end] <= 'z' && s[end] >= 'a' || s[end] <= 'Z' && s[end] >= 'A'))
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            else if ((s[start] <= 'z' && s[start] >= 'a' || s[start] <= 'Z' && s[start] >= 'A')
            && !(s[end] <= 'z' && s[end] >= 'a' || s[end] <= 'Z' && s[end] >= 'A'))
            {
                end--;
            }
            else if (!(s[start] <= 'z' && s[start] >= 'a' || s[start] <= 'Z' && s[start] >= 'A')
            && (s[end] <= 'z' && s[end] >= 'a' || s[end] <= 'Z' && s[end] >= 'A'))
            {
                start++;
            }
            else
            {
                start++;
                end--;
            }
        }
        return s;
    }
};