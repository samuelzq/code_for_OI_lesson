#include <cstdio>   // getchar()

int main(void)
{
    bool o = false;
    char c;

	while ((c = getchar()) != EOF) {
		if (c == 'H' || c == 'Q' || c == '9')
			o = true;
	}

	if (o == true)
		printf("YES\n");
	else
		printf("NO\n");
    return 0;
}
