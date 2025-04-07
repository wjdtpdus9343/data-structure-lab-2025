#include <iostream>
#include <climits>   // INT_MIN
using namespace std;

int main() {
    int arr[100];     // 최대 100개까지 입력 받는다고 가정
    int n;            // 입력 개수

    printf("몇 개의 숫자를 입력하시겠습니까? ");
    scanf_s("%d", &n);

    if (n <= 0 || n > 100) {
        printf("입력 개수는 1~100 사이여야 합니다.\n");
        return 1;
    }

    printf("%d개의 정수를 입력하세요:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf_s("%d", &arr[i]);
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    printf("최댓값: %d\n", maxVal);

    return 0;
}
