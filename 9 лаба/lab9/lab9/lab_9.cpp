#include <iostream>
#include "Varpram.h"
#include <cstdarg>
using namespace std;

namespace Varparm {

    int ivarparm(int n, ...) {
        if (n <= 0)
            return 0;

        int pr = 1;
        va_list args;
        va_start(args, n);

        for (int i = 0; i < n; ++i) {
            pr *= va_arg(args, int);
        }

        va_end(args);
        return pr;
    }

    int svarparm(short a, ...) {
        if (a <= 0)
            return 0;

        short* p = &a;
        short result = *p;
        va_list args;
        va_start(args, a);

        for (int i = 0; i < a; ++i) {
            short value = va_arg(args, int);
            if (value > result) {
                result = value;
            }
        }

        va_end(args);
        return result;
    }

  double fvarparm(float a, ...)
  {
    va_list args;
    va_start(args, a);

    double sum = 0.0;
    float value = a;

    while (value != FLT_MAX)
    {
      sum += value;
      value = va_arg(args,double);
    }

    va_end(args);

    return sum;
  }

  double dvarparm(double a, ...)
  {
    va_list args;
    va_start(args, a);

    double sum = 0.0;
    double value = a;

    while (value != DBL_MAX)
    {
      sum += value;
      value = va_arg(args, double);
    }

    va_end(args);

    return sum;
  }
}

int main()
{
  setlocale(0, "");
  cout << "ivarparm" << endl;
  cout<<Varparm::ivarparm(1,5)<<endl;
  cout << Varparm::ivarparm(2, 5, 6) << endl;
  cout << Varparm::ivarparm(3, 5, 6, 7) << endl;
  cout << Varparm::ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

  cout << endl<<"svarpram"<<endl;
  cout<<Varparm::svarparm(1,5)<<endl;
  cout << Varparm::svarparm(2, 5, 6) << endl;
  cout << Varparm::svarparm(3, 5, 6, 7) << endl;
  cout << Varparm::svarparm(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;

  cout << endl << "fvarparm" << endl;
  cout<<Varparm::fvarparm(FLT_MAX)<<endl;
  cout << Varparm::fvarparm(5.0, FLT_MAX) << endl;
  cout << Varparm::fvarparm(5.0, 6.0, FLT_MAX) << endl;
  cout << Varparm::fvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, FLT_MAX) << endl;

  cout << endl << "dvarparm" << endl;
  cout<<Varparm::dvarparm(DBL_MAX)<<endl;  
  cout<<Varparm::dvarparm(5.0, DBL_MAX)<<endl;
  cout << Varparm::dvarparm(5.0, 6.0, DBL_MAX) << endl;  
  cout << Varparm::dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, DBL_MAX) << endl;

  return 0;
}