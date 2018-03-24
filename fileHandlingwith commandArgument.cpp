/*
John, 34, 12-07-2015,99999,manager,fulltime
Jack, 36,15-08-2016,90000,clerk,fulltime
Peter, 40, 10-10-2010,120000,ceo,fulltime
Jonny, 27, 12-12-2008,50000,auditor,parttime
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *file;

int main(int argc , char *argv[])
{

	file = fopen(argv[1],"r+");
	char str[200];

	while(!feof(file))
	{
		int count = 0;
		int j = 0;
		int num = 0;;
		char number[10];
		fgets(str,200,file);
		for (int i = 0; i < strlen(str); ++i)
		{	
			if(count == 3 && str[i] != ',')
			{
				number[j] = str[i];
				j++;
			}
			if(str[i] == ',')
				count++;
		}
		num = atoi(number);
		printf("%d\n",num);
	}
	fclose(file);

return 0;
}