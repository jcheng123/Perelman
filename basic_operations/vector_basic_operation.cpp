#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
Todo:[2019.03.10-2019.03.17]
Implementation of vector addition.
Implementation of vector division.
Implementation of vectors' rank & maximal linearly independent system.

*/


int VecNorm(const vector<float> &m, const int mode, float &res)
{
    int ret = 0;
    if (m.empty())
    {
        cout << "The input vector should \
                 not be empty."
             << endl;
        ret = -1;
        return ret;
    }

    // Infinite norm.
    if (mode == -1)
    {
        res = m[0];
        for (int i = 0; i < m.size(); ++i)
            res = max(res, m[i]);

        return ret;
    }

    res = 0.0;
    for (int i = 0; i < m.size(); ++i)
    {
        float elem_power = pow(m[i], mode);
        res += elem_power;
    }
    res = pow(res, 1.0 / mode);
    return ret;
}

void unitest(void)
{
    /* Test VecNorm */
    vector<float> test_case_2 = {1.0, 2.0, 3.0, -1.0, -2.0, -3.0};
    int idx = -1;
    int ret = 0;
    float res;
    ret = VecNorm(test_case_2, idx, res);
    cout << "Testing VecNorm: " << res
         << " State code is: " << ret << endl;
}

int main()
{
    unitest();
    return 0;
}
