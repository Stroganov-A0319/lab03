#include <iostream>
#include <vector>
#include "Head.h"
using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

vector<double>
input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}
Input
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    in >> data.bin_count;

    return data;
}
vector<size_t> make_histogram(vector<double> numbers, size_t bin_count, double& min, double& max)
{
    vector<size_t> bins(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}
int
main()
{
    // Ввод данных
    Input input = read_input(cin);

    // Обработка данных
    double min = input.numbers[0];
    double max = input.numbers[0];
    find_minmax(input.numbers, min, max);

    vector<size_t> bins = make_histogram(input.numbers, input.bin_count, min, max);
    // Вывод данных


    show_histogram_svg(bins);



    return 0;
}
