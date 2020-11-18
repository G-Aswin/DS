#include<stdio.h>
#include<string.h>

// 1. program to implement strrev with out using inbuilt function
// 2. program to implement strcmp with out using inbuilt function
// 3. program to implement pattern search program
// 4. program to implement search and replace multiple occurrences .

int str_cmp(char s1[], char s2[])
{
    int i, iter;

    // To set iter to the max sixe of s1 or s2
    if (strlen(s1) > strlen(s2))
    {
        iter = strlen(s1);
    }
    else
    {
        iter = strlen(s2);
    }

    // Iterate each char and compare
    for (i = 0; i < iter; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }

    return 0;    
}

void strrv(char s[], char s2[])
{
    // Copies the src to dst iterating backwards
    int n = strlen(s);
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        s2[i] = s[j];
    }
    s2[n] = '\0';
}

char* strjoin(char *dest, char* src)
{
    int i, j;
    for(i=0; dest[i]!='\0'; ++i); 
    for(j=0; src[j]!='\0'; ++j, ++i)
    {
      dest[i]=src[j];
    }
    dest[i] = '\0';
    
    return dest;
}

char* strjoin2(char *dest, char* src)
{
    int i = 0, j = strlen(dest);

    for (i = 0; i < strlen(src); i++, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    
    return dest;
}


/*OCTOBER 2nd

p-> pattern, t->text

len(p) = r, len(t) = s

k = 1, max = s - r + 1
while k <= max
    for l = 1 to R
        if p[l] != T[k + l - 1]
    index = k
    k += 1
if not, idx = 0
exit

*/

int find_pattern(char pattern[], char text[])
{
    int p = strlen(pattern), t = strlen(text);
    int max = t - p + 1;

    for (int k = 0; k < max; k++)
    {
        int x;
        for (x = 0; x < p; x++)
        {
            if (pattern[x] != text[k + x])
                break;
        }
        if (x == p)
            return k;
    }

    return -1;
}

int find_pattern_from(char pattern[], char text[], int start)
{
    int p = strlen(pattern), t = strlen(text);
    int max = t - p + 1;

    for (int k = start; k < max; k++)
    {
        int x, y;
        for (x = 0; x < p; x++)
        {
            if (pattern[x] != text[k + x])
                break;
        }
        if (x == p)
            return k;
    }

    return -1;
}

int find_pattern_from_window(char pattern[], char text[], int start)
{
    int p = strlen(pattern), t = strlen(text);
        int x;
    for (x = 0; x < p; x++)
    {
        if (pattern[x] != text[start + x])
            break;
    }
    if (x == p)
        return 1;

    return 0;
}





int main()
{
    // char t1[] = "ind", t2[25] = "ind";
    // printf("CMP Value : %d", str_cmp(t1,t2));
    // strrv(t1, t2);
    // printf("rev of %s is %s", t1, t2);

    // strjoin(t2, t1);
    // printf("\njoint t2 %s\n", t2);

    // strjoin2(t2, t1);
    // printf("\njoint t2 %s\n", t2);

    char text[] = "ComputerScience";
    char pattern[] = "cien";

    int result = find_pattern_from_window(pattern, text, 9);
    if (result == -1)
    {
        printf("\nPattern not found\n");
    }
    else{
        printf("\nPattern found at idx %d\n", result);
    }

    return 0;
}