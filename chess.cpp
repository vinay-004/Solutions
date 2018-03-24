#include<cstdio>
#include<algorithm>

int main() {

	int t;

	scanf("%d", &t);

	while (t > 0) {
		int xc = 0;
		int yc = 0;
		char chesspiece;
		scanf(" %c %d %d", &chesspiece, &xc, &yc);
	
		if (chesspiece == 'r') {
			printf("%d\n", std::min(xc, yc));
		}
		if (chesspiece == 'k') {
			int ans = (xc * yc +1)/2;
			printf("%d\n", ans);
		}
		if (chesspiece == 'K') {
			int ans = ((std::min(xc, yc) + 1) / 2)* ((std::max(xc, yc) + 1) / 2);
			printf("%d\n", ans);
		}
		if (chesspiece == 'Q') {
			printf("%d\n", std::min(xc, yc));
		}
		
		t--;
	}



}