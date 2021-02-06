#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
size_t strlen(const char* str)
{
	assert(str != NULL);
	char* eos = str;

	while (*eos++);

	return eos - str - 1;
}

int main()
{
	char str[] = "bit";

	printf("%d\n", strlen(str));

	return 0;
}