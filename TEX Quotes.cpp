#include<cstdio>

int main() {

	char a;
	int count = 0;
	while (scanf("%c", &a) != EOF)
	{
		if (a == '"') {
			if(count%2 == 0)
				printf("``");
			if (count % 2 == 1) {
				printf("''");
			}
			count++;
		}
		else {
			printf("%c", a);
		}
		
	}
}