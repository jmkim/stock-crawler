#include "../src/RetrieveData.hpp"

int main ()
{
  stock_crawler::RetrieveDataFromYahooFinance ("^IXIC", "1399474800", "1494169200", "1d");
  return 0;
}
