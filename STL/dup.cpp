#include <gtest/gtest.h>

#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> unique(vector<T> const& first, vector<T> const& second)
{
    // TODO:      This function should join input vectors and return only unique elements.
    // Important: Use only containers! No algorithms allowed.

    vector<T> Connected_Vectors = first;
    Connected_Vectors.insert(Connected_Vectors.end(), second.begin(), second.end());


    unordered_set<T> Unique_Elements(Connected_Vectors.begin(), Connected_Vectors.end());
    Connected_Vectors.assign(Unique_Elements.begin(), Unique_Elements.end());
    return vector<T>{Connected_Vectors};
}

TEST(DupTest, Test)
{
    vector<double> d1 = {1.1, 2.1, 3.1, 1.0, 1.1, 0.56, 0.44, 4.445, 0.001, 9.996, 0.001};
    vector<double> d2 = {0.001, 0.002, 0.0003, 1.1, 0.44, 0.99, 0.996, 3.1, 3.12};

    vector<double> expected = {1.0, 0.002, 1.1, 0.0003, 2.1, 0.44, 0.001, 0.996, 4.445, 3.1, 9.996, 0.56, 3.12, 0.99};
    auto actual = unique(d1, d2);
    sort(begin(expected), end(expected));
    sort(begin(actual), end(actual));
    ASSERT_EQ(expected, actual);
}

int main(int ac, char ** av)
{
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

