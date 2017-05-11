#include "../src/RetrieveData.hpp"

/*
    Retrieve the NASDAQ Composite (^IXIC) stock data from Yahoo Finance
    between 2014-05-08 and 2017-05-05 with interval 1 day.
*/
int main ()
{
  stock_crawler::RetrieveDataFromYahooFinance ("^IXIC", "1399474800", "1494169200", "1d");
  return 0;
}
