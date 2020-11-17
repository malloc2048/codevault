#include <iostream>
#include "market_data.h"

int main( int argc, char** argv ) {
    MarketData md;
    md.read_input();

    md.run_query();

    system( "PAUSE" );
    return 0;
}