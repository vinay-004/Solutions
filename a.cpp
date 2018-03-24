#include<cstdio>

int main(int argc, char const *argv[])
{
	long long unsigned f[3];

	for (int i = 0; i < 3; ++i)
	{
		f[i] = 1;
	}

	for (int i = 2; i < 100; ++i)
	{
		f[2] = f[1] + f[0];
		printf("%llu\n", f[2]);
		f[0] = f[1];
		f[1] = f[2];
	}

	return 0;
}