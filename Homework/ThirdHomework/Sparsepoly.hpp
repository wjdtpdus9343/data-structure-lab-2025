#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101               // 다항식의 최대 기억한 최대 차수 + 1

class SparsePoly {
    int numTerms;                    // 다항식 항의 개수
    std::vector<int> exponents;      // 각 항의 차수 저장 벡터
    std::vector<float> coefficients; // 각 항의 계수 저장 벡터

public:
    // 생성자
    SparsePoly() { numTerms = 0; }

    // 다항식 입력 함수
    void read(){
        printf("항의 개수를 입력하세요: ");
        scanf_s("%d", &numTerms);

        exponents.clear();
        coefficients.clear();

        for (int i = 0; i < numTerms; i++) {
            float coef;
            int exp;
            printf("%d번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ", i + 1);
            scanf_s("%f %d", &coef, &exp);

            if (coef != 0) {
                coefficients.push_back(coef);
                exponents.push_back(exp);
            }
        }
        numTerms = coefficients.size();
    }

    // 다항식 출력 함수
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

    // 다항식 덧셈 함수
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