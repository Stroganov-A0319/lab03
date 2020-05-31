#ifndef SVG_C_INCLUDED
#define SVG_C_INCLUDED
#include "Head.h"

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void
svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}
void
svg_end()
{
    cout << "</svg>\n";
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}
void
show_histogram_svg(const vector<size_t>& bins)
{

    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    size_t IMAGE_WIDTH;
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    size_t number_count = 0;
    for (size_t bin: bins)
    {
        number_count += bin;
    }

    do
    {
        cout << "Enter the image_width";
        cin >> IMAGE_WIDTH;
        if (IMAGE_WIDTH < 70)
            flag1 = true;
        if (IMAGE_WIDTH > 800)
            flag2 = true;
        if (IMAGE_WIDTH < (number_count / 3) * BLOCK_WIDTH)
            flag3 = true;
    }
    while (!flag1 or !flag2 or !flag3);
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scalei = (max_count * BLOCK_WIDTH) > (IMAGE_WIDTH - TEXT_WIDTH);
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double controled = (IMAGE_WIDTH - TEXT_WIDTH) / (max_count * BLOCK_WIDTH);
    double top = 0;

    for (size_t bin : bins)
    {
        double bin_width = BLOCK_WIDTH * bin;
        if (!scalei)
        {
            controled = bin_width;
        }
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, controled, BIN_HEIGHT, "red", "darkblue");
        top += BIN_HEIGHT;
    }
    svg_end();
}

#endif // SVG_C_INCLUDED
