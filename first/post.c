#include<stdio.h>
#include<ctype.h>
int stack[20];
int top=-1;

void push (int x)
{
	stack[++top]=x;
}

int pop()
{
	return stack[top--];
}

int main()
{
	char exp[20];
	int n1,n2,n3,num;
	printf("enter the value for exp\n");
	scanf("%s",exp);
	char *e=exp;

	while(*e != '\0')
	{
		if(isdigit(*e))
		{
			num=*e-48;
			printf("%d\n",num);
			push(num);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(*e)
			{
				case '+':
					{
						n3=n2+n1;
						break;
					}
				case '-':
					{
						n3=n2-n1;
						break;
					}
				case '/':
					{
						n3=n2/n1;
						break;
					}
				case '*':
					{
						n3=n2*n1;
						break;
					}
			}
			push(n3);
		}
		e++;
	}
	printf("Result %s = %d\n",exp,pop());
	return 0;
}
