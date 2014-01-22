#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int length,i,j,k,m;
char key[10],key2[10],keytemp[10];
char temp[100][100],temp2[100][100],t;
char text[100],text2[100];
printf("Enter plain text(no spaces):\n");
scanf("%s",text);
printf("Enter your key(10 max): ");
scanf("%s",key);
length=strlen(key);
k=0,i=0;
int flag=1;
while(flag==1)
{
	for(j=0;j<length;j++)
	{
		if(text[k]=='\0' || flag==0)
		{
			temp[i][j]='$';
			flag=0;
		}
		else
			temp[i][j]=text[k];
		k++;
	}
	i++;
}
i--;
k=i;
for(i=0;i<length-1;i++)
{
		for(j=0;j<length-1-i;j++)
		{
			if(key[j]>key[j+1])
			{
				t=key[j];
				key[j]=key[j+1];
				key[j+1]=t;
				for(m=0;m<=k;m++)
				{
					t=temp[m][j];
					temp[m][j]=temp[m][j+1];
					temp[m][j+1]=t;
				}

			}
		}
}


printf("Your encrypted text is : \n");
for(i=0;i<length;i++)
{
	for(j=0;j<=k;j++)
	{
		//if(temp[j][i]!='$')

			printf("%c",temp[j][i]);
	}
}
printf("\n\n");
printf("Enter encrypted text :\n ");
scanf("%s",text2);
printf("Enter decreption key: ");
scanf("%s",key2);
strcpy(keytemp,key2);
int tot=strlen(text2);
int keyl=strlen(key2);
int line=tot/keyl;
k=0;
for(i=0;i<keyl;i++)
       for(j=0;j<line;j++)
       {
		if(text2[k]!='\0')
			temp[j][i]=text2[k];
		k++;
       }
int n=0;
while(n!=keyl)
{
	for(i=0;i<keyl-1;i++)
	{
		for(j=0;j<keyl-1-i;j++)
		{
			if(key2[j]>key2[j+1])
			{
				t=key2[j];
				key2[j]=key2[j+1];
				key2[j+1]=t;
				for(m=0;m<line;m++)
				{
					t=temp[m][j];
					temp[m][j]=temp[m][j+1];
					temp[m][j+1]=t;
				}

			}
		}
	}
	strcpy(key2,keytemp);
	n++;
}
cout<<"\nPlain text is: ";
for(i=0;i<line;i++)
{	for(j=0;j<keyl;j++)
		if(temp[i][j]!='$')
			cout<<temp[i][j];
}
printf("\n");
getch();
return 0;
}
