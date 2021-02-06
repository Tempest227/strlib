//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
char* strcat(char *dest, const char *src)
{
	char* res = dest;

	while (*dest++);
	dest--;
	while (*dest++ = *src++);

	return res;
}
//
//int main()
//{
//	char src[] = "bit";
//	char dest[10] = "hello";
//
//	printf("%s\n", strcat(dest, src));
//
//	return 0;
//}