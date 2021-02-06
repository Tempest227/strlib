//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <assert.h>
//
char* strstr(const char* string, const char* str)
{
	assert(string && str);

	const char* cp = string;
	const char* p1 = cp;
	const char* p2 = str;

	while (*cp)
	{
		p1 = cp;
		p2 = str;
		while ((*p1) && (*p2) && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return cp;
		}
		else
		{
			cp++;
		}
	}
	return NULL;
}
//
//int main()
//{
//	char* string = "The quick brown dog jumps over the lazy fox";
//	char* str = "lazy";
//	char* res = strstr(string, str);
//
//	if (res != NULL)
//	{
//		printf("%s\n", res);
//	}
//	else
//	{
//		printf("NOT FOUND\n");
//	}
//	
//
//	return 0;
//}