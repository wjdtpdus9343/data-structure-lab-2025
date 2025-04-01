int findMaxPixel(int a[][5], int h, int w) {
    int maxPixel = a[0][0];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] > maxPixel) {
                maxPixel = a[i][j];
            }
        }
    }
    return maxPixel;
}

int main() {
    int image[3][5] = {
        {10, 20, 30, 40, 50},
        {60, 70, 80, 90, 100},
        {110, 120, 130, 140, 150}
    };
    int max = findMaxPixel(image, 3, 5);
    return 0;
}
