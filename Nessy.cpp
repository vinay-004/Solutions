#include<cstdio>

int main() {
	
	int v = 0;
	int a = 0;
	int b = 0;
	scanf("%d", &v);

	while (v--) {
		scanf("%d%d", &a, &b);
		 long ans = (a / 3) * (b / 3);
		printf("%ld\n", ans);
		ans = 0;
	}



}