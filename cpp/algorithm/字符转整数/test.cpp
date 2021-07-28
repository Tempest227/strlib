class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        //跳过空格
        while(i < s.size() && s[i] == ' ')
            i++;
        int j = i;
        bool flag = true;
        //判断符号
        if (i < s.size())
        {
            if (s[i] == '+')
            {
               flag = true; 
               i++;
            }
            else if (s[i] == '-')
            {
               flag = false; 
               i++;
            }
            
        }
        //处理数字
        long result = 0;
        while(i < s.size() && isdigit(s[i]))
        {            
            result = result * 10 + (s[i] - '0');
            if (flag && result >= INT_MAX)
            {
                return INT_MAX;
            }
            else if (!flag  && -result <= INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }

        return flag?(int)result:(int)(-result);
       
        
    }
};