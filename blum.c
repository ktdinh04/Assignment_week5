#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool primeInit[1000005]; // Mảng bool để đánh dấu số nguyên tố

void erathorness(int n) { // Tìm tất cả các số nguyên tố nhỏ hơn hoặc bằng N
    for (int i = 0; i <= n; i++) {
        primeInit[i] = true; // Khởi tạo ban đầu là tất cả các số đều là nguyên tố
    }
    primeInit[0] = primeInit[1] = false; // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        if (primeInit[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                primeInit[j] = false; // Đánh dấu các số không nguyên tố
            }
        }
    }
}

void blumFunc(int n, int blum) {
    erathorness(n);
    // Khởi tạo danh sách các số Blum
    int *blumSeries = (int *)malloc(100000 * sizeof(int));
    int blumCount = 0;

    int *primeList = (int *)malloc((n / 2) * sizeof(int));
    int primeCount = 0;

    primeList[primeCount++] = 2; // Số nguyên tố đầu tiên là 2
    for (int i = 3; i <= n; i += 2) {
        if (primeInit[i] == true) primeList[primeCount++] = i;
    }

    for (int i = 0; i < primeCount - 1; i++) {
        for (int j = i + 1; j < primeCount; j++) {
            if ((primeList[i] * primeList[j]) % 4 == 3) {
                blumSeries[blumCount++] = primeList[i] * primeList[j];
            }
        }
    }

    free(primeList); // Giải phóng bộ nhớ cho mảng primeList

    // In ra danh sách các số Blum nếu có
    printf("The total blum list (if available): ");
    bool available = false;
    for (int i = 0; i < blumCount; i++) {
        for (int j = 0; j < blumCount; j++) {
            if (blumSeries[j] > blumSeries[i]) { // Đảm bảo j lớn hơn i
                for (int k = 0; k < blumCount; k++) {
                    if (blumSeries[k] == blumSeries[i] + blumSeries[j]) {
                        available = true;
                        printf("%d ", blumSeries[i] + blumSeries[j]);
                    }
                }
            }
        }
    }
    if (!available) {
        printf("Not available");
    }
    
    // Tìm số Blum trong chuỗi số Blum
    available = false;
    for (int i = 0; i < blumCount; i++) {
        if (blumSeries[i] == blum) {
            printf("\nThe blum %d exists!\n", blum);
            available = true;
            break;
        }
    }
    if (!available) {
        printf("\nThe blum %d does not exist.\n", blum);
    }

    free(blumSeries); // Giải phóng bộ nhớ cho mảng blumSeries
}

int main() {
    int n, blum;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the blum number to search: ");
    scanf("%d", &blum);

    blumFunc(n, blum);

    return 0;
}
