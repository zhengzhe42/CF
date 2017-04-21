#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>

using namespace std;

int main()
{
    int n, x[1000], y[1000]; double D = DBL_MAX; cin >> n;

    for( int i = 0; i < n; i++ )
        cin >> x[i] >> y[i];

    for( int i = n-1, j = 0, k = 1; j < n; j++ )
    {
        long long dx1 = x[j] - x[i], dy1 = y[j] - y[i], dx2 = x[k] - x[i], dy2 = y[k] - y[i];

        double D1 = 0.5 * fabs( dx1 * dy2 - dx2 * dy1 ) / sqrt(  dx2 * dx2 + dy2 * dy2 );

        if ( D1 < D )
            D = D1;

        if ( ++i == n )
            i = 0;

        if ( ++k == n )
            k = 0;
    }

    cout << fixed << setprecision(10) << D * (1.0 - DBL_EPSILON);