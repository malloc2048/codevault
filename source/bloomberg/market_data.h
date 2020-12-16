#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <map>
#include <string>
#include <vector>

struct Tick
{
    std::string timestamp;
    std::string ticker;
    std::string asset;
    std::string bank;
    double buy;
    double sell;
};

class MarketData
{
public:
    typedef std::vector<std::string> QueryContainer_t;
    typedef std::vector<std::string>::iterator QueryContainerItr_t;
    
    typedef std::vector<Tick*> TickList_t;
    typedef std::vector<Tick*>::iterator TickListItr_t;
    typedef std::map<std::string, TickList_t> TickContainer_t;
    typedef std::map<std::string, TickList_t>::iterator TickContainerItr_t;
    
    MarketData();

    void run_query();
    void read_input();
    void make_tick( std::string str, int count );

private:
    std::string trim( std::string& str );
    void print_banks( std::string& ticker );
    void print_tickers( std::string& asset );
    int time_compare( std::string& tick_time_str, std::string& range_time_str );
    void max_profit( std::string& ticker, std::string& range_low, std::string range_high );
    
    std::vector<std::string> parse_query_str( std::string& str );
    std::vector<std::string> parse_ticker_str( std::string& str, const char delim );

private:
    QueryContainer_t _queries; 
    TickContainer_t _ticks_by_asset;
    TickContainer_t _ticks_by_ticker;
    
    static const int TICK_NUM_PARAMS;
    static const std::string TICK_STR;
    static const char TICK_PARAMETER_DELIM;

    static const std::string QUERY_STR;
    static const std::string QUERY_PARAMTER_DELIM;
    static const std::string QUERY_ALL_BANKS_FOR_TICKER;
    static const std::string QUERY_ALL_TICKERS_FOR_ASSET;
    static const std::string QUERY_BEST_RETURNS_FOR_TICKER_IN_TIME_RANGE;
};

#endif