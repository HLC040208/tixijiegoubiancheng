#include <iostream>
#include <windows.h>

using namespace std;

const int N = 10000;

long long freq, head, tail;

void recursion(int *a, int n) {
    if (n == 1)
        return;
    else {
        for (int i = 0; i < n / 2; i++) {
            a[i] += a[n - i - 1];
        }
        recursion(a, n / 2);
    }
}

int main() {
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    for (int l = 1; l <= 10; l++) {
        double totalTime = 0;
        int n;
        cin >> n;
        for (int k = 0; k < 1000; k++) {
            int a[N];
            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }

            QueryPerformanceCounter((LARGE_INTEGER *)&head);

            recursion(a, n);

            QueryPerformanceCounter((LARGE_INTEGER *)&tail);

            // 累计每次计时的时间
            totalTime += (tail - head) * 1000.0 / freq;
        }

        // 计算平均时间
        double averageTime = totalTime / 1000;
        cout << "Average Time: " << averageTime << "ms" << endl;
    }

    system("pause");

   
}