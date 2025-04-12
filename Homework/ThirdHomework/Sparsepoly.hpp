#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101               // ���׽��� �ִ� ����� �ִ� ���� + 1

class SparsePoly {
    int numTerms;                    // ���׽� ���� ����
    std::vector<int> exponents;      // �� ���� ���� ���� ����
    std::vector<float> coefficients; // �� ���� ��� ���� ����

public:
    // ������
    SparsePoly() { numTerms = 0; }

    // ���׽� �Է� �Լ�
    void read(){
        printf("���� ������ �Է��ϼ���: ");
        scanf_s("%d", &numTerms);

        exponents.clear();
        coefficients.clear();

        for (int i = 0; i < numTerms; i++) {
            float coef;
            int exp;
            printf("%d��° ���� ����� ������ �Է��ϼ��� (��:��� ����): ", i + 1);
            scanf_s("%f %d", &coef, &exp);

            if (coef != 0) {
                coefficients.push_back(coef);
                exponents.push_back(exp);
            }
        }
        numTerms = coefficients.size();
    }

    // ���׽� ��� �Լ�
    void display(const char* str) {
        printf("%s", str);
        if (numTerms == 0) {
            printf("0.0\n");
            return;
        }
        for (int i = 0; i < numTerms; i++) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i < numTerms - 1) printf(" + ");
        }
        printf("\n");
    }

    // ���׽� ���� �Լ�
    void add(SparsePoly a, SparsePoly b) {
        numTerms = 0;
        exponents.clear();
        coefficients.clear();

        int i = 0, j = 0;

        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] > b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                i++;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                j++;
            }
            else {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sum);
                }
                i++; j++;
            }
        }

        while (i < a.numTerms) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            i++;
        }
        while (j < b.numTerms) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            j++;
        }

        numTerms = coefficients.size();
    }
};