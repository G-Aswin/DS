char* str_reverse(int n,char s1[])
{
    char rev[n];
    for(int i=n-1;i>=0;i--)
    {
        rev[n-i]=s1[i];
    }
    return rev;
}


int main()
{
    int t = 4;
    char t1[4]="indi";
    char reverse[4] = str_reverse(t,t1);
    for(int i=0;i<t;i++){
        printf("%c",reverse[i]);
    }
    
    return 0;
}