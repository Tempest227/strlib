char* strncat(char* strDest, char* strSource, size_t count)
{
	char* t = strDest;
	while (*strDest)
	{
		strDest++;
	}	

	while (count--)
	{
		*strDest++ = *strSource++;
	}
	*strDest = '\0';
	
	return t;
}