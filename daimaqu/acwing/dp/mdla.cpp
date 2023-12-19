#include <iostream>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << 12;

long long f[N][M]; // i-1叉到i,相当于存储i-1

bool st[M];

int n, m;

int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i++)
        {
            st[i] = true;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        st[i] = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                st[i] = false;
        }

        memset(f, 0, sizeof f);

        f[0][0] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < 1 << n; j++) // 相当于i-1
            {
                for (int k = 0; k < 1 << n; k++) // 相当于i-2
                {
                    if ((j & k) == 0 && st[j | k])
                        f[i][j] += f[i - 1][k];
                    // 由这两种更新出
                    // 其实相当于更新i-1
                }
            }
        }

        cout << f[m][0] << endl;
    }

    return 0;
}
