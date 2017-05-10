//
// Created by jmkim on 5/10/17.
//

#include "RetrieveData.hpp"

int
stock_crawler::RetrieveDataFromYahooFinance (const std::string &stock_item,
                                             const std::string &period_start,
                                             const std::string &period_end,
                                             const std::string &period_interval,
                                             const std::string &out_csv_path,
                                             const std::string &temp_dir_path
)
{
  YahooFinance out (stock_item, period_start, period_end, period_interval, out_csv_path, temp_dir_path);
  return out.RetrieveData ();
}

int
stock_crawler::RetrieveDataFromYahooFinance (const std::string &stock_item,
                                             const std::string &period_start,
                                             const std::string &period_end,
                                             const std::string &period_interval,
                                             const std::string &out_csv_path,
                                             const std::string &temp_cookie_path,
                                             const std::string &temp_html_path
)
{
  YahooFinance out (stock_item,
                    period_start,
                    period_end,
                    period_interval,
                    out_csv_path,
                    temp_cookie_path,
                    temp_html_path
  );
  return out.RetrieveData ();
}
