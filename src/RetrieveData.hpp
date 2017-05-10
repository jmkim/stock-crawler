//
// Created by jmkim on 5/10/17.
//

#ifndef STOCK_CRAWLER_RETRIEVEDATA_HPP
#define STOCK_CRAWLER_RETRIEVEDATA_HPP

#include <string>
#include "yahoo_finance/YahooFinance.hpp"

namespace stock_crawler
{
int
RetrieveDataFromYahooFinance (const std::string &,
                              const std::string &,
                              const std::string &,
                              const std::string & = "1d",
                              const std::string & = "./csv/result.csv",
                              const std::string & = "./temp"
);

int
RetrieveDataFromYahooFinance (const std::string &,
                              const std::string &,
                              const std::string &,
                              const std::string &,
                              const std::string &,
                              const std::string &,
                              const std::string &
);
}

#endif //STOCK_CRAWLER_RETRIEVEDATA_HPP
