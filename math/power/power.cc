#include <func.h>

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
        {
            return 1;

        }

        if(exponent == 1)
        {
            return base;

        }

        unsigned int absExponent;
        if(exponent > 0)
        {
            absExponent = exponent;

        }else{
            absExponent = -exponent;

        }

        double result = PowerWithUnsignedExponent(base, absExponent);
        if(exponent < 0)
        {
            result = 1.0 / result;

        }
        return result;

    }

    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        if(exponent == 1)
        {
            return base;
        }
        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if((exponent & 0x1) == 1)
        {
            result *= base;

        }
        return result;
    }

};

int main(int argc, char* argv[])
{

    return 0;
}

