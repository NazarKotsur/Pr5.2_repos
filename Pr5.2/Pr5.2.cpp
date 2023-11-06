#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{


    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "log" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = 2.0 / x;
        S = a;
        do {
            n++;
            R = (2.0 * n - 1.0) / ((2.0 * n + 1.0) * pow(x, 2));
            a *= R;
            S += a;
        } while (abs(a) >= eps);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log((static_cast<double>(x) + 1) / (static_cast<double>(x) - 1)) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = 2.0/x;
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = (2.0 * n - 1.0) / ((2.0 * n + 1.0) * pow(x, 2));
    a *= R;
    return a;
}