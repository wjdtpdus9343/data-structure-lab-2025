#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // 이미지 흑백(Grayscale)으로 읽기
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다. 파일 경로를 확인하세요." << std::endl;
        return -1;
    }

    // 최대 밝기 값 구하기
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // 정수형으로 출력
    std::cout << static_cast<int>(maxVal) << std::endl;

    return 0;
}
