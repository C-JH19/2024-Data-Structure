#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void shellSort(int list[], int n) {
    for (int k = n / 2 ; k > 0 ; k /= 2) {
        if (k % 2 == 0) {
            k += 1;
        }

        // k만큼 떨어진 요소들을 삽입 정렬 수행.
        for (int i = k ; i < n ; i++) {
            int temp = list[i];
            int j;
            for (j = i ; j >= k && list[j - k] > temp ; j -= k) {
                list[j] = list[j - k];
            }
            list[j] = temp;
        }
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** shell Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    shellSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}