#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // �̹��� ���(Grayscale)���� �б�
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�. ���� ��θ� Ȯ���ϼ���." << std::endl;
        return -1;
    }

    // �ִ� ��� �� ���ϱ�
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // ���������� ���
    std::cout << static_cast<int>(maxVal) << std::endl;

    return 0;
}
