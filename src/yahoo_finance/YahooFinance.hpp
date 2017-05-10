//
// Created by jmkim on 5/10/17.
//

#ifndef STOCK_CRAWLER_YAHOOFINANCE_HPP
#define STOCK_CRAWLER_YAHOOFINANCE_HPP

#include <string>
#include "../RetrieveDataInterface.hpp"

namespace stock_crawler
{
class YahooFinance : public RetrieveDataInterface {
 public:
  YahooFinance (const std::string &stock_item,
                const std::string &period_start,
                const std::string &period_end,
                const std::string &period_interval,
                const std::string &out_csv_path,
                const std::string &temp_cookie_path,
                const std::string &temp_html_path)
      : stock_item_ (stock_item),
        period_start_ (period_start),
        period_end_ (period_end),
        period_interval_ (period_interval),
        temp_cookie_path_ (temp_cookie_path),
        temp_html_path_ (temp_html_path),
        out_csv_path_ (out_csv_path)
  {}

  YahooFinance (const std::string &stock_item,
                const std::string &period_start,
                const std::string &period_end,
                const std::string &period_interval = "1d",
                const std::string &out_csv_path = "./csv/result.csv",
                const std::string &temp_dir_path = "./temp")
      : YahooFinance (stock_item,
                      period_start,
                      period_end,
                      period_interval,
                      out_csv_path,
                      temp_dir_path + "/cookies.txt",
                      temp_dir_path + "/step_one.html")
  {}

  int RetrieveData (void);

  inline const std::string &stock_item (void) const { return stock_item_; }
  inline void set_stock_item (const std::string &stock_item) { stock_item_ = stock_item; }
  inline const std::string &period_start (void) const { return period_start_; }
  inline void set_period_start (const std::string &period_start) { period_start_ = period_start; }
  inline const std::string &period_end (void) const { return period_end_; }
  inline void set_period_end (const std::string &period_end) { period_end_ = period_end; }
  inline const std::string &period_interval (void) const { return period_interval_; }
  inline void set_period_interval (const std::string &period_interval) { period_interval_ = period_interval; }
  inline const std::string &out_csv_path (void) const { return out_csv_path_; }
  inline void set_out_csv_path (const std::string &out_csv_path) { out_csv_path_ = out_csv_path; }
  inline const std::string &temp_cookie_path (void) const { return temp_cookie_path_; }
  inline void set_temp_cookie_path (const std::string &temp_cookie_path) { temp_cookie_path_ = temp_cookie_path; }
  inline const std::string &temp_html_path (void) const { return temp_html_path_; }
  inline void set_temp_html_path (const std::string &temp_html_path) { temp_html_path_ = temp_html_path; }

 private:
  std::string MakeUrlStepOne (void);
  std::string MakeUrlStepTwo (const std::string &);
  static std::string GetCrumbFromHtml (const std::string &);
  int RetrieveUrlStepOne (FILE *);
  int RetrieveUrlStepTwo (FILE *, const std::string &);

  std::string stock_item_;
  std::string period_start_;
  std::string period_end_;
  std::string period_interval_;
  std::string out_csv_path_;
  std::string temp_cookie_path_;
  std::string temp_html_path_;
};

}

#endif //STOCK_CRAWLER_YAHOOFINANCE_HPP
