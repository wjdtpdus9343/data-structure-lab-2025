#include <iostream>
using namespace std;

// 최댓값 구하는 함수
int findMax(int arr[], int size) {
    int max = arr[0];  // 첫 번째 값을 최댓값으로 설정
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // 더 큰 값이 있으면 교체
        }
    }
    return max;
}

int main() {
    int numbers[] = { 5, 3, 9, 2, 7 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int maxValue = findMax(numbers, size);
    cout << "최댓값은: " << maxValue << endl;

    return 0;
}
