#include <iostream>
#include <windows.h>

using namespace std;

const int N = 500;

int main() {
    for(int l = 1; l <= 10; l++) {
        long long head, tail, freq;
        int n;
        cin >> n;

        int a[N];
        for(int i = 1; i <= n; i++) {
            a[i] = i;
        }

        int b[N][N];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                b[i][j] = i + j;
            }
        }

        int sum[N] = {0}; // 初始化为0

        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&head);

        // 增加内部循环次数来提高精度
        int innerLoopIterations = 1000; // 设置内部循环次数
        for(int iteration = 0; iteration < innerLoopIterations; iteration++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    for(int k = 1; k <= n; k++) {
                        sum[i] += b[j][i] * a[j];
                    }
                }
            }
        }

        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        cout << "Col: " << (tail - head) * 1000.0 / (freq * innerLoopIterations) << "ms" << endl;

        for(int i = 1; i <= n; i++) {
            cout << sum[i] << " ";
        }
    }
    system("pause");
    
}