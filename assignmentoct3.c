#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int copy_str_match(char *dest, char *replace, int des_pos)
{
    for (int j = 0; j < strlen(replace); j++)
    {
        dest[des_pos] = replace[j];
        des_pos++; 
    }
    return des_pos;
}

char *strreplace(char *dest, char *text, char *find, char *replace)
{
    int n = strlen(text), r = strlen(replace), f = strlen(find);
    int i = 0, t = 0;

    while (t < n)
    {
        if (find_pattern_from_window(find, text, t))
        {
            i = copy_str_match(dest, replace, i);
            t += f;
        }
        else
        {
            dest[i] = text[t];
            i++;
            t++;
        }
    }
    dest[i] = '\0';
    return dest;
}








int main()
{
    char dest[50];
    char text[] = "RNS is a good college, really good.";

    printf("\nThe original string is : %s", text);

    strreplace(dest, text, "good", "ok");

    printf("\nThe modified string is : %s", dest);


    return 0;
}