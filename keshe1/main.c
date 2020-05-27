#include <stdio.h>


#define SOLD 0;
//车厢数组
int arr[20][5];

//安排在编号最小的几个空座位中
void find(int o) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (arr[i][j] != 0) {
                printf("%d", arr[i][j]);
                arr[i][j] = 0;
            }
        }
    }
}

void list(int n, int *l) {
    //票数数组
    for (int i = 0; i < n; ++i) {
        int o = l[i];
        //遍历车厢数组寻找合适座位
        for (int j = 0; j < 20; ++j) {
            //统计每一排是否有足够座位
            int s = 0;
            for (int k = 0; k < 5; ++k) {
                if (arr[j][k] != 0) {
                    s++;
                }
            }
            //如果这行有足够座位
            if (s >= o) {
                for (int k = 0; k < 5; ++k) {
                    if (arr[j][k] != 0) {
                        printf("%d", arr[j][k]);
                        arr[j][k] = 0;
                    }
                }
                break;
                //这行没有足够座位
            } else {
                //如果还未到最后一排
                if (j < 19) {
                    continue;
                    //如果已经到了最后一行则调用find函数从小到大排序
                } else {
                    find(o);
                }
            }
        }
    }
}


int main() {
    //为车厢数组赋值
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j] = 5 * i + j + 1;
        }
    }
    int n, b;
    printf("请输入购票指令的数量");
    scanf("%d", &n);
    int l[n];
    for (int k = 0; k < n; ++k) {
        printf("请依次输入每个指令要购买的票数");
        scanf("%d", &b);
        if (b >= 0 && b < 5) {
            l[n] = b;
        }
    }
    //调用方法
    list(n, l);
    return 0;
}