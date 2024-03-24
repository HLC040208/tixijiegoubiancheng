#include <iostream>
#include <windows.h>

using namespace std;

const int N = 10000;

int main() {
    long long freq, head, tail;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

for(int l=1;l<=10;l++)
{
    double totalTime = 0;
    int n;
        cin >> n;
    for(int k = 0; k < 1000; k++) {
    
        int a[N];
        for(int i = 1; i <= n; i++) {
            a[i] = i;
        }

        QueryPerformanceCounter((LARGE_INTEGER *)&head);

        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += a[j];
        }

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