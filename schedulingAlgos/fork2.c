// Online C compiler to run C program online
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sumOdd = 0, sumEven = 0, n, i;
	printf("Name:Pankaj Chadda\tSection:I\tRollNo:33\n");
	n = fork();
	if (n > 0) {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 == 0)
				sumEven = sumEven + a[i];
		}
		printf("Parent Process\n");
        printf("Even sum:%d\n",sumEven);
	}
	else {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 != 0)
				sumOdd = sumOdd + a[i];
		}
		printf("Child Process\n");
		printf("Odd sum:%d",sumOdd);
	}
	return 0;
}
