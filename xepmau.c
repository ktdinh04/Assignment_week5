#include <stdio.h>
#include <string.h>

enum Colors { DO = 0, TRANG = 1, XANH = 2 };
const char* color_names[] = {"do", "trang", "xanh"};

int main() {
    int n;
    printf("Nhap so luong doi tuong: ");
    scanf("%d", &n);
    
    char input_color[10];  
    enum Colors color_values[n];  
    printf("Nhap cac mau (xanh, do, trang):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", input_color);

        if (strcmp(input_color, "do") == 0) {
            color_values[i] = DO;
        } else if (strcmp(input_color, "trang") == 0) {
            color_values[i] = TRANG;
        } else if (strcmp(input_color, "xanh") == 0) {
            color_values[i] = XANH;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (color_values[i] > color_values[j]) {
                enum Colors temp = color_values[i];
                color_values[i] = color_values[j];
                color_values[j] = temp;
            }
        }
    }
    printf("Result color:");
    for (int i = 0; i < n; i++) {
        printf("%s ", color_names[color_values[i]]);  
    }

    return 0;
}
