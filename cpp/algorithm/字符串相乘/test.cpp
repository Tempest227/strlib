class Solution {
public:
    string multiply(string num1, string num2) {
        //边界条件
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        if (num1 == "1")
        {
            return num2;
        }
        if (num2 == "1")
        {
            return num1;
        }

        int totalLen = num1.size() + num2.size();
        int ret[totalLen];
        memset(ret, 0, sizeof(ret));
        //num[i] 和 num[j] 相乘结果存放于 [i+j, i+j+1]
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int n2 = num2[j] - '0';
                int s = ret[i + j + 1] + n1 * n2;
                ret[i + j] += s / 10;
                ret[i + j + 1] = s % 10;
            }
        }

        string retStr;
        for (int i = 0; i < totalLen; i++)
        {
            if (i == 0 && ret[i] == 0)continue;
            retStr += to_string(ret[i]);
        }

        return retStr;
    }
};