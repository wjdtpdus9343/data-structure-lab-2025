#include <cstdio>

int findArrayMax(int score[], int n)  // �ڷᱸ��: �迭 array, n�� �迭 ����
{
    int tmp = score[0];  // ù ��° ��Ҹ� �ִ� �ӽ� ���� ������ �Ҵ�

    for (int i = 1; i < n; i++) {  // �˰���: �迭�� �� ��° ��Һ��� ���������� Ž��
        if (score[i] > tmp) {    // ���� ��Ұ� �ӽ� �ִ񰪺��� ũ��
            tmp = score[i];      // �ش� ��Ҹ� ���ο� �ִ����� ������Ʈ
        }
    }

    return tmp;  // ã�� �ִ� ��ȯ
}

// �� �Լ�
void main()
{
    int score[5] = { 1, 10, 2, 4, 5 };  // ũ�Ⱑ 5�� ���� �迭 �ʱ�ȭ
    int out;                            // ������� ������ ���� ����

    out = findArrayMax(score, 5);       // �迭���� �ִ� ã�� �Լ� ȣ��
    printf("result = %d", out);         // ��� ���: "result = 10"
}