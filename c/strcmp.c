//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <assert.h>
//
int strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1++ == *str2++)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
	}

	return (*str1 - *str2) ? 1 : -1;
}
//
//int main()
//{
//	char str1[] = "bit";
//	char str2[] = "atom";
//
//	printf("%d\n", strcmp(str1, str2));
//
//	return 0;
//}