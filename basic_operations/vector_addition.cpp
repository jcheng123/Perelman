#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int VecAddition(const vector<float>& m, const float& alpha, vector<float> &res)
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
        res.push_back(m[i] + alpha);

    return ret;
}

int VecAddition(const vector<float>& m, const vector<float>& n, vector<float> &res)
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

    for (int i = 0; i < m.size(); ++i)
        res.push_back(m[i] + n[i]);

    return ret;
}

void unitest(void)
{
    /* Test VecAddition */
    vector<float> test_case = {1.0, 3.2, 10.3, -2.3, 0.0};
    float alpha = 10.0;
    vector<float> result;
    int ret = VecAddition(test_case, alpha, result);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Testing VecAddition: " << i << '\t'
             << test_case[i] << '\t'
             << alpha << '\t'
             << result[i] << '\t'
             << endl;
    }

    vector<float> test_case_1 = {1.0, 2.0, 3.0, -1.0, -2.0, -3.0};
    vector<float> test_case_2 = {0.5, 0.0, -0.2, -0.4, 0.1, 0.9};
    vector<float> res;
    ret = VecAddition(test_case_1, test_case_2, res);
    for (int i = 0; i < test_case_1.size(); ++i)
        cout << "Testing VecAddition: " << i << '\t'
             << test_case_1[i] << '\t'
             << test_case_2[i] << '\t'
             << res[i] << '\t'
             << endl;
}

int main()
{
    unitest();
    return 0;
}