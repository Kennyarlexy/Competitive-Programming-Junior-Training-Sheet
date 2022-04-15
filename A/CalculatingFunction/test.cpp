//below's solution is way to large before the substraction

#include <bits/stdc++.h>
using namespace std;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main() {
    long long n; cin >> n;
    
    __int128_t n_dec = (n+1) / 2, n_inc = n/2;
    __int128_t res_inc = (n_inc/2.0)*(2*2 + (n_inc - 1)*2);
    __int128_t res_dec = (n_dec/2.0)*(2*-1 + (n_dec - 1)*-2);
    __int128_t result = res_inc + res_dec;
    cout << result << "\n";
    
    return 0;
}