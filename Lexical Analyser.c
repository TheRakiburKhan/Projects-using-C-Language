#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", 							"double", "else", "enum", "extern", "float", "for", "goto", "if", "int", 							"long", "register", "return", "short", "signed", "sizeof", "static", "struct", 						"switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main()
{
    int choice;
    part:
    printf("\n1 for lexical analysis from a file\n2 for lexical analysis from an input expression\n3 for exit\n\nEnter a choice:");
    scanf("%d",&choice);


    if(choice==1)
    {
    char ch, buffer[15], operator_s[] = "+-*/%=";
	char filename[1001], temp;
	FILE *fp;
	int a,b=0;


	fipen:
		printf("Provide name of the file: ");
		getchar();
		gets(filename);

		fp = fopen(filename,"r");

		if(fp == NULL)
		{
			printf("error while opening the file!!! Check file name and case...\n");
			printf("\n\nDo you want to try again!!!\nPress any key to try again or N/n to quit: ");
			scanf("%c",&temp);
			getchar();
			if(temp=='n' || temp=='N')
			{
				goto part;
			}
			else
			{
				system("cls");
				goto fipen;
			}

		}

	while((ch = fgetc(fp)) != EOF)
	{
   		for(a = 0; a < 6; ++a)
		{
   			if(ch == operator_s[a])
			{
   				printf("%c is operator\n", ch);
			}
   		}

   		if(isalnum(ch))
		{
   			buffer[b++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (b != 0))
		{
   				buffer[b] = '\0';
   				b = 0;

   				if(isKeyword(buffer) == 1)
   					printf("%s is keyword\n", buffer);
   				else
   					printf("%s is indentifier\n", buffer);
   		}

	}

	fclose(fp);
    }



    else if(choice==2)
    {

    char exp[100],operators[100];
    char variables[20][20];
    int ascii[100],constants[100];
    int len,number=0;
    int i=0,j=-1,k=-1,l=-1,n=0;
    int pr[10]={0},m=0;

    printf("\n         ''Lexical Analyzer''       \n\n");
    printf("Enter the string:");
    getchar();
    gets(exp);
    len=strlen(exp);
    printf("\nLength of the string is %d\n",len);
    for(i=0;i<len;i++)
    {
        ascii[i]=(int)exp[i];
    }
    for(i=0;i<len;i++)
    {
        if(isdigit(exp[i]))
        {
            while(isdigit(exp[i]))
            {
                number=10*number+ascii[i]-'0';
                i++;
            }
            j++;
            constants[j]=number;
            number=0;
        }
        if(isalpha(exp[i]))
        {
            while(isalpha(exp[i])||isdigit(exp[i])||exp[i]=='_')
            {
                k++;
                variables[m][k]=exp[i];
                i++;
            }
            m++;
            pr[n]=k;
            n++;
            k=-1;
        }
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='='||exp[i]=='^')
        {
            l++;
            operators[l]=exp[i];
        }
    }
    printf("\nThe Constants are:\n");
    for(i=0;i<=j;i++)
    {
        printf("\tConstant%d\t%d\n",i+1,constants[i]);
    }
    printf("\nThe operators are:\n");
    for(i=0;i<=l;i++)
    {
        printf("\toperator%d\t%c\n",i+1,operators[i]);
    }
    printf("\nThe variables are:");
    for(i=0;i<m;i++)
    {
        printf("\n\tvariable%d\t",i+1);
        for(j=0;j<=pr[i];j++)
        {
            printf("%c",variables[i][j]);
        }
    }
    printf("\n");
     goto part;

    }

    else if(choice==3)
    {
        exit(0);
    }

	return 0;
}
