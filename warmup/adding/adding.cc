#include <iostream>

int reverse(int x)
{
    int res = 0;

    while(x != 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main ()
{
    std::ios::sync_with_stdio(false);

	int cases, a, b;

    scanf("%d", &cases);

    while(cases--)
	{
        scanf("%d %d", &a, &b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}
	return 0;
}