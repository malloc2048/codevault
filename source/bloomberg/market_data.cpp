#include <sstream>
#include <iostream>
#include "market_data.h"

const int MarketData::TICK_NUM_PARAMS( 6 );
const std::string MarketData::TICK_STR( "TICK" );
const char MarketData::TICK_PARAMETER_DELIM( '|' );

const std::string MarketData::QUERY_STR( "QUERY" );
const std::string MarketData::QUERY_PARAMTER_DELIM( "\"" );
const std::string MarketData::QUERY_ALL_BANKS_FOR_TICKER( "allBanksForTicker" );
const std::string MarketData::QUERY_ALL_TICKERS_FOR_ASSET( "allTickersForAsset" );
const std::string MarketData::QUERY_BEST_RETURNS_FOR_TICKER_IN_TIME_RANGE( "bestReturnsForTickerInTimeRange" );

MarketData::MarketData(){}

void MarketData::run_query()
{
    QueryContainerItr_t itr;
    for( itr = _queries.begin(); _queries.end() != itr; ++itr )
    {
        std::vector<std::string> params = parse_query_str( *itr );
        if( 0 < params.size() )
        {
            if( std::string::npos != itr->find( QUERY_ALL_BANKS_FOR_TICKER ) )
            {
                print_banks( params[0] );
            }
            else if( std::string::npos != itr->find( QUERY_ALL_TICKERS_FOR_ASSET ) )
            {
                print_tickers( params[0] );
            }
            else if( std::string::npos != itr->find( QUERY_BEST_RETURNS_FOR_TICKER_IN_TIME_RANGE ) &&
                3 == params.size() )
            {
                max_profit( params[0], params[1], params[2] );
            }
        }
    }
}

void MarketData::read_input()
{
    int count = 0;
    std::string line;

    std::getline( std::cin, line );

    while( !line.empty() )
    {
        if( std::string::npos != line.find( TICK_STR ))
        {
            make_tick( line.substr( TICK_STR.length() + 1 ), count );
            count++;
        }
        else if( std::string::npos != line.find( QUERY_STR ) )
        {
            line.erase( 0, QUERY_STR.size() );
            _queries.push_back( line );
        }
        std::getline( std::cin, line );
    }
}

void MarketData::make_tick( std::string str, int count )
{
    std::vector<std::string> params = parse_ticker_str( str, TICK_PARAMETER_DELIM );
    if( TICK_NUM_PARAMS == params.size() )
    {
        Tick* tick = new Tick();
        tick->timestamp = params[0];
        tick->ticker    = params[1];
        tick->asset     = params[2];
        tick->bank      = params[3];
        tick->buy       = std::stod( params[4] );
        tick->sell      = std::stod( params[5] );

        _ticks_by_asset[params[2]].push_back( tick );
        _ticks_by_ticker[params[1]].push_back( tick );
    }
}

std::string MarketData::trim( std::string& str )
{
    return str.substr( str.find_first_not_of( " " ) );
}

void MarketData::print_banks( std::string& ticker )
{
    TickContainerItr_t itr = _ticks_by_ticker.find( ticker );
    if( _ticks_by_ticker.end() != itr )
    {
        std::cout << "RESULT: " << QUERY_ALL_BANKS_FOR_TICKER << "(" << ticker << ") - ";
        for( int i = 0;  i < itr->second.size(); i++ )
        {
            if( i != 0 )
                std::cout << ", ";
            std::cout << itr->second[i]->bank;
        }
        std::cout << std::endl;
    }
}

void MarketData::print_tickers( std::string& asset )
{
    TickContainerItr_t itr = _ticks_by_asset.find( asset );
    if( _ticks_by_asset.end() != itr )
    {
        std::cout << "RESULT: " << QUERY_ALL_TICKERS_FOR_ASSET << "(" << asset << ") - ";
        for( int i = 0; i < itr->second.size(); i++ )
        {
            if( i != 0 )
                std::cout << ", ";
            std::cout << itr->second[i]->ticker;
        }
        std::cout << std::endl;
    }
}

int MarketData::time_compare( std::string& tick_time_str, std::string& range_time_str )
{
    // Return 0 if tick_time == range_time 
    // else return 1 if tick_time > range_time
    // else return -1 if tick_time < range_time
    std::vector<std::string> tick_tokens = parse_ticker_str( tick_time_str, ':' );
    std::vector<std::string> range_tokens = parse_ticker_str( range_time_str, ':' );

    int tick_time = (
        std::stoi( tick_tokens[0] ) * 100 +
        std::stoi( tick_tokens[1] ) * 10 +
        std::stoi( tick_tokens[2] ) );

    int range_time = (
        std::stoi( range_tokens[0] ) * 100 +
        std::stoi( range_tokens[1] ) * 10 +
        std::stoi( range_tokens[2] ) );

    if( tick_time < range_time )
        return -1;
    if( tick_time > range_time )
        return 1;
    return 0;
}

void MarketData::max_profit( std::string& ticker, std::string& range_low, std::string range_high )
{
    TickContainerItr_t itr = _ticks_by_ticker.find( ticker );
    if( _ticks_by_ticker.end() != itr )
    {
        std::cout << "RESULT: " << QUERY_BEST_RETURNS_FOR_TICKER_IN_TIME_RANGE << "(\"" <<
            ticker << "\", " << range_low << ", " << range_high << ") ";

        double buy = 0.0;
        std::string buy_time;
        double sell = 0.0;
        std::string sell_time;
        std::string bank;
        for( int i = 0; i < itr->second.size(); i++ )
        {
            int time_cmp_low = time_compare( itr->second[i]->timestamp, range_low );
            int time_cmp_high = time_compare( itr->second[i]->timestamp, range_high );
            if( -1 != time_cmp_low && 1 != time_cmp_high )
            {
                if( buy > itr->second[i]->buy || buy == 0.0 )
                {
                    buy = itr->second[i]->buy;
                    buy_time = itr->second[i]->timestamp;
                }
                if( sell < itr->second[i]->sell )
                {
                    sell = itr->second[i]->sell;
                    bank = itr->second[i]->bank;
                    sell_time = itr->second[i]->timestamp;
                }
            }
        }
        std::cout << "BUY:" << buy_time << "|" << buy <<
            "; SELL:" << sell_time << "|" << sell << "|" << bank << std::endl;
    }
}

std::vector<std::string> MarketData::parse_query_str( std::string& str )
{
    std::vector<std::string> params;
    std::size_t start = str.find( QUERY_PARAMTER_DELIM );
    while( std::string::npos != start )
    {
        std::size_t stop = str.find( QUERY_PARAMTER_DELIM, start + 1 );
        params.push_back( str.substr( start + 1, stop - start - 1 ) );
        start = str.find( QUERY_PARAMTER_DELIM, stop + 1 );
    }
    return params;
}

std::vector<std::string> MarketData::parse_ticker_str( std::string& str, const char delim )
{
    std::vector<std::string> params;
    std::stringstream ss( str );
    std::string param;
    while( std::getline( ss, param, delim ) )
    {
        params.push_back( trim( param ));
    }
    return params;
}