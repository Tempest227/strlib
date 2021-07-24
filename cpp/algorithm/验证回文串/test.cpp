class Solution {
public:
    bool isLetterOrNumber(char c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        //将大写全部转成小写
        for (auto& ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
        }
        int start = 0;
        int end = s.size() - 1;

        while(start < end)
        {
            while(start < end && !isLetterOrNumber(s[start]))
            {
                start++;
            }

            while(end > start && !isLetterOrNumber(s[end]))
            {
                end--;
            }

            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};