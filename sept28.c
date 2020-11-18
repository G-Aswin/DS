#include <stdio.h>
#include <string.h>
#include <math.h>

typedef union u
{
	int a;
	char c[20];
} U;



void string_stats(char *string)
{
	int count_v = 0, count_c = 0;
	int n = strlen(string);
	for (int i = 0; i < n; i++)
	{
		switch (string[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': 
				count_v += 1;
				break;
		case ' ':
				break;
		
		default:
			count_c += 1;
			break;
		}
	}

	printf("\nVowels = %d\nConsonants = %d\n", count_v, count_c);
}


void str_copy(char dest[20], char src[20])
{
	int i;
	for (i = 0; i <= strlen(src); i++)
	{
		dest[i] = src[i];
	}
}

//Q. WAP to accept a string and prints its ascii
int count_digits(int n) // Not needed when using log
{
	int c = 0;
	while (n != 0){
		c += 1;
		n /= 10;
	}
	return c;
}


void str_to_ascii(char *src, char *res){
	int i, j = 0;
	for (i = 0; i < strlen(src); i++)
	{
		sprintf((res + j), "%d", src[i]);
		j += (log10(src[i]) + 1);
	}
	res[j] = '\0';
}


int main()
{
	char str[20] = "abcde";
	// char dest[20];
	// string_stats(str);
	// str_copy(dest, str);
	// printf("\nSource = %s\nDestination = %s\n", str, dest);
	char res[strlen(str)*3];
	str_to_ascii(str, res);
	printf("\nThe ascii string is %s.\n", res);
    return 0;
}