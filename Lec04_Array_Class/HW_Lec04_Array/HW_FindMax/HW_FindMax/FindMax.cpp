#include <iostream>
using namespace std;

// �ִ� ���ϴ� �Լ�
int findMax(int arr[], int size) {
    int max = arr[0];  // ù ��° ���� �ִ����� ����
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // �� ū ���� ������ ��ü
        }
    }
    return max;
}

int main() {
    int numbers[] = { 5, 3, 9, 2, 7 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int maxValue = findMax(numbers, size);
    cout << "�ִ���: " << maxValue << endl;

    return 0;
}
