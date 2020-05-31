#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>

using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(const Input& data);
#endif // HEAD_H_INCLUDED
