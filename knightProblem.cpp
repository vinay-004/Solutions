// https://math.stackexchange.com/questions/614812/maximum-number-of-knights-on-a-2-times-n-n-ge-2-board?rq=1


#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, minNum, maxNum, numbers;

	while (scanf("%d %d", &n, &m), n + m)
	{
		minNum = min(n, m);
		maxNum = max(n, m);


		if (minNum == 1)
			numbers = maxNum;

		else if (minNum == 2)
		{
			numbers = 4 * int(maxNum / 4) + 2 * min(2, maxNum % 4);
		}

		else
			numbers = (n * m + 1) / 2;

		printf("%d knights may be placed on a %d row %d column board.\n", numbers, n, m);
	}
}