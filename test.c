#include <stdio.h>
#include<string.h>
//stack pri
int F( char symbol)
{
	switch(symbol)
	{
		case '+' :
		case '-' : return 2;
		case '*' :
		case '/' : return 4;
		case '^' :
		case '$' : return 5;
		case '(': return 0;
		case '#': return -1;
		default: return 8; 
	}
}
//input priority
int G( char symbol)
{
	switch(symbol)
	{
		case '+' :
		case '-' : return 1;
		case '*' :
		case '/' : return 3;
		case '^' :
		case '$' : return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7; 
	}
}
void push(char S[20],int *top, char symbol)
{
    (*top)++;
    S[*top]=symbol;
}
char pop(char S[20],int *top)
{
    char elem;
    elem=S[*top];
    (*top)--;
    return elem;
}

int main()
{
    char infix_expr[20]="a+b/d^b^s^(x/y+z)";
    char S[20],symbol,postfix[20];
    int i,top=-1,j=0;
    //intiali
    push(S,&top,'#');
    //procedure
    //read evey symbol
    for(i=0;i<strlen(infix_expr);i++)
    {
        symbol=infix_expr[i];
        while(F(S[top])> G(symbol)) 
            postfix[j++]=pop(S,&top);
        if(F(S[top])!= G(symbol))
            push(S,&top,symbol);
        else
            top--;
    }    
    while(S[top]!='#')
        postfix[j++]=pop(S,&top);
    postfix[j]='\0';
    printf("postfix expr is %s",postfix);
    return 0;
}
