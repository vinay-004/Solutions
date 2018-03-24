#include<cstdio>
#include<algorithm>
int main() 
{

	int a, b, c;

	
	
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		bool crossCheck = !((c % 8 == b % 8) || (c / 8 == b / 8));
		bool q = a < std::max(b, c) && a > std::min(b, c);
		
		bool HorizontalCheck = ((b - a) % 8 == 0 && (a - c)% 8 == 0) && q ;
		bool VerticalCheck = (b / 8 == a / 8 ) && (a /8 == c / 8)  && q;
		//printf("%d %d %d\n", crossCheck, HorizontalCheck, VerticalCheck);
		if (a == b) 
		{
			printf("Illegal state\n");
			continue;
		}
		if (crossCheck || HorizontalCheck || VerticalCheck || a == c || b == c) 
		{
			printf("Illegal move\n");
			continue;
		}
		
		int diff = std::max(a, c) - std::min(a, c);

		if (diff == 8 || (diff == 1) && a / 8 == c / 8) {
			printf("Move not allowed\n");
			continue;
		}

		if ((a == 0 && c == 9) || (a == 7 && c == 14) || (a == 56 && c == 49) || (a == 63 && c == 54))
			printf("Stop\n");
		else 
		{
			printf("Continue\n");
		}
			
		}
		
	}

