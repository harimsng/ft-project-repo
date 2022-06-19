#include <stdio.h>
#include <stdlib.h>

static int s1 = 2;
static int s2 = 3;

int	main(int argc, char *argv[], char *envp[])
{
	int			a = 1;
	int			b = 1.0;
	int			c = 'a';
	int			arr[3] = { 1.0, 2.0, 3.0 };
	int			*ap;
	int			*bp;
	int			*cp;
	static int	ss1 = 3;
	static int	ss2 = 4;

	ap = (int *)malloc(sizeof(int));
	bp = (int *)malloc(sizeof(int));
	cp = (int *)malloc(sizeof(int));
	printf("환경 변수\n>> %p\n", envp);
	printf("명령줄 인수\n>> %p\n", argv + argc - 1);
	printf("로컬 변수\n>> %p\n>> %p\n>> %p\n", &a, &b, &c);
	printf("로컬 배열\n>> %p\n>> %p\n>> %p\n", arr, arr + 1, arr + 2);
	printf("동적 할당\n>> %p\n>> %p\n>> %p\n",
			ap, bp, cp);
	printf("전역 정적 변수\n>> %p\n>> %p\n", &s1, &s2);
	printf("지역 정적 변수\n>> %p\n>> %p\n", &ss1, &ss2);
	printf("읽기 전용 영역\n>> %p\n", "a");
	return (0);	
}
