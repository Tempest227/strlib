class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;
        string retStr;

        while(end1 >= 0 || end2 >= 0)
        {
            int val1 = 0;
            if (end1 >= 0)
            {
                val1 = num1[end1] - '0';
                end1--;
            }

            int val2 = 0;
            if (end2 >= 0)
            {
                val2 = num2[end2] - '0';
                end2--;
            }

            int ret = val1 + val2 + next;
            if (ret > 9)
            {
                next = 1;
                ret -= 10;
            }
            else
            {
                next = 0;
            }
            retStr += ('0' + ret);
        }
        if (next == 1)
        {
            retStr += '1';
        }
        reverse(retStr.begin(), retStr.end());

        return retStr;
    }
};