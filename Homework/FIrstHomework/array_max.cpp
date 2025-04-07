#include <iostream>
#include <climits>   // INT_MIN
using namespace std;

int main() {
    int arr[100];     // �ִ� 100������ �Է� �޴´ٰ� ����
    int n;            // �Է� ����

    printf("�� ���� ���ڸ� �Է��Ͻðڽ��ϱ�? ");
    scanf_s("%d", &n);

    if (n <= 0 || n > 100) {
        printf("�Է� ������ 1~100 ���̿��� �մϴ�.\n");
        return 1;
    }

    printf("%d���� ������ �Է��ϼ���:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf_s("%d", &arr[i]);
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    printf("�ִ�: %d\n", maxVal);

    return 0;
}
