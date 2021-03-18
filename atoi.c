int my_atoi(const char* str)
{
	int sign = 1;
	int t = 0;
	int cnt = 0;
	const char* eos = str;
	int flag = 1;
	//标记符号位
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	//一开始碰到字母就返回 0
	if ((*str > 'a' && *str < 'z') || (*str > 'A' && *str < 'Z'))
	{
		return 0;
	}
	//跳过空白符号
	while (isspace(*str) > 0)
	{
		str++;
	}
	//读取连续数字字符
	while (*str >= '0' && *str <= '9')
	{
		//跳过连0串
		if (*str == '0' && flag)
		{
			str++;
			eos = str;			
		}
		else
		{			
			flag = 0;//首位为0标记
			//计算数字串长度，首位为'-'/'+'，长度减一
			while (*eos >= '0' && *eos <= '9' || *eos == '-' || *eos == '+')
			{
				if (*eos == '-' || *eos == '+')
					cnt--;
				cnt++;
				eos++;
			}
			//加权求和
			t += (*str - '0')*pow(10, --cnt);
			str++;
		}		
	}
	//返回计算结果和符号位的乘积
	return t * sign;
}