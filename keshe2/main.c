#include <stdio.h>

//坐标轴数组
int arr[100][100];


int main() {
    int n, x1, y1, x2, y2;
    printf("请输入要画的矩形的个数");
    scanf("%d", &n);
    if (n >= 0 && n <= 100) {
        //设置数组用于存储坐标
        int a[n][4];
        //输入坐标
        for (int i = 0; i < n; ++i) {
            printf("请输入要画的矩形的左下角的横坐标");
            scanf("%d", &x1);
            if (x1 >= 0 && x1 <= 100) {
                a[i][0] = x1;
            }
            printf("请输入要画的矩形的左下角的纵坐标");
            scanf("%d", &y1);
            if (y1 >= 0 && y1 <= 100) {
                a[i][1] = y1;
            }
            printf("请输入要画的矩形的右上角的横坐标");
            scanf("%d", &x2);
            if (x2 >= 0 && x2 <= 100) {
                a[i][2] = x2;
            }
            printf("请输入要画的矩形的右下角的纵坐标");
            scanf("%d", &y2);
            if (y2 >= 0 && y2 <= 100) {
                a[i][3] = y2;
            }
        }
        //面积数组
        int s[n];
        //重叠数
        int c = 0;
        //总面积
        int S = 0;
        for (int j = 0; j < n; ++j) {
            //计算面积，并储存
            s[j] = (a[j][2] - a[j][0]) * (a[j][3] - a[j][1]);
            S = s[j] + S;
            //涂色，若未涂色则为NULL，若已涂色为1
            for (int i = a[j][0]+1; i <= a[j][2]; ++i) {
                for (int k = a[j][1]+1; k <= a[j][3]; ++k) {
                    //若该色块不为NULL
                    if (arr[i][k] != NULL) {
                        //重叠一次就加一
                        c++;
                    } else {
                        arr[i][k] = 1;
                    }
                }
            }
        }
        S = S - c;
        printf("%d", S);
    } else {
        printf("输入错误");
    }
    return 0;
}