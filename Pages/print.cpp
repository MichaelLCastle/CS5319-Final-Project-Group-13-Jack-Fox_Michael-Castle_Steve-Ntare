//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "print.h"

void print( Position pos, string s, int linelength )
{
    int spaces = 0;
    switch( pos )
    {
        case CENTER: spaces = ( linelength - s.size() ) / 2; break;
        case RIGHT : spaces =   linelength - s.size()      ; break;
    }
    if ( spaces > 0 ) cout << string( spaces, ' ' );
    cout << s << '\n';
}
