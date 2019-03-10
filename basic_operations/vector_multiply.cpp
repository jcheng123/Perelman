#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int VecProduct(vector<float> m, float alpha, vector<float> &res)
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

    for (int i = 0; i < m.size(); ++i)
        res.push_back(alpha * m[i]);

    return ret;
}

int VecProduct(vector<float> m, vector<float> n, float &res)
{
    int ret = 0;
    if (m.empty() || n.empty())
    {
        cout << "The input vectors should \
                 not be empty."
             << endl;
        ret = -1;
        return ret;
    }

    if (m.size() != n.size())
    {
        cout << "The two input vectors should \
                 be of the same length."
             << endl;
        ret = -2;
        return ret;
    }

    res = 0.0;
    for (int i = 0; i < m.size(); ++i)
        res += m[i] * n[i];

    return ret;
}

void unitest(void)
{
    /* Test VecProduct */
    vector<float> test_case = {1.0, 3.2, 10.3, -2.3, 0.0};
    float alpha = 10.0;
    vector<float> result;
    int ret = VecProduct(test_case, alpha, result);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Testing VecProduct: " << i
             << " Input value is: " << test_case[i]
             << " Output value is: " << result[i]
             << " State code is: " << ret << endl;
    }

    vector<float> test_case_1 = {1.0, 2.0, 3.0, -1.0, -2.0, -3.0};
    float value;
    ret = VecProduct(test_case_1, test_case_1, value);
    cout << "Testing VecProduct: " << value
         << " State code is: " << ret << endl;
}

int main()
{
    unitest();
    return 0;
}