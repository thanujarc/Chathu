#include <iostream>
#include <math.h>
using namespace std;

float getMidPont(float a, float b)
{
    return (a + b) / 2;
}

float getY(float x)
{
    return pow(x, 3) - x - 2;
}

float findRoot(int MAX, float a, float b, float tolerance)
{
    int n = 0;
    float c;
    float y_c;
    float y_a;
    while (n < MAX)
    {
        c = getMidPont(a, b);
        y_c = getY(c);
        y_a = getY(a);
        
        if (y_c == 0 || tolerance > (b - a) / 2)
        {
            return c;
        }
        if (y_c * y_a > 0.0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        n++;
    }
    return NULL;
};

int main()
{

    float root = findRoot(100, 1, 2, 0.0001);
    cout << root << "\n";
    return 0;
}