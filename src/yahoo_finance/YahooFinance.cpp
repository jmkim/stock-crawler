#include "YahooFinance.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <curl/curl.h>

//
// Created by jmkim on 5/8/17.
//
int
stock_crawler::YahooFinance::RetrieveData (void)
{
  int ret_val = 0;
  FILE *html;

  std::cout << "=== Variables ===\n"
            << "Stock Item        " << stock_item_ << "\n"
            << "Period Start      " << period_start_ << "\n"
            << "Period End        " << period_end_ << "\n"
            << "Period Interval   " << period_interval_ << "\n"
            << "Temp file path    " << temp_html_path_ << "\n"
            << "Temp file path    " << temp_cookie_path_ << "\n"
            << "Output path       " << out_csv_path_ << "\n"
            << "=================\n";

  html = std::fopen (temp_html_path_.c_str (), "w");

  if (html == nullptr)
    {
      std::cerr << "Error: Cannot open file (" << temp_html_path_ << ").\n";
      return 99;
    }

  if ((ret_val = RetrieveUrlStepOne (html)) != 0)
    { return (100 + ret_val); };

  std::fclose (html);

  html = std::fopen (out_csv_path_.c_str (), "w");
  if (html == nullptr)
    {
      std::cerr << "Error: Cannot open file (" << out_csv_path_ << ").\n";
      return 199;
    }

  std::string crumb = GetCrumbFromHtml (temp_html_path_);
  std::cout << "CrumbStore is '" << crumb << "'.\n" << std::flush;

  if ((ret_val = RetrieveUrlStepTwo (html, crumb)) != 0)
    { return (200 + ret_val); };

  std::fclose (html);
  std::cout << "Saved to '" << out_csv_path_ << "'\n";

  return ret_val;
}

std::string
stock_crawler::YahooFinance::MakeUrlStepOne (void)
{
  std::stringstream out (std::ios_base::app | std::ios_base::out);
  out << "https://finance.yahoo.com/quote/"
      << stock_item_
      << "/history?period1="
      << period_start_
      << "&period2="
      << period_end_
      << "&interval="
      << period_interval_
      << "&filter=history&frequency="
      << period_interval_;
  return out.str ();
}

std::string
stock_crawler::YahooFinance::MakeUrlStepTwo (const std::string &crumb)
{
  std::stringstream out (std::ios_base::app | std::ios_base::out);
  out << "https://query1.finance.yahoo.com/v7/finance/download/"
      << stock_item_
      << "?period1="
      << period_start_
      << "&period2="
      << period_end_
      << "&interval="
      << period_interval_
      << "&events=history&crumb="
      << crumb;
  return out.str ();
}

std::string
stock_crawler::YahooFinance::GetCrumbFromHtml (const std::string &html_path)
{
  std::string html;
  {
    std::ifstream html_file (html_path);
    html_file.seekg (0, std::ios::end);
    html.reserve ((unsigned) html_file.tellg ());
    html_file.seekg (0, std::ios::beg);
    html.assign ((std::istreambuf_iterator<char> (html_file)), std::istreambuf_iterator<char> ());
  }

  std::string out;
  std::string::size_type pos = html.find ("CrumbStore");
  if (pos != std::string::npos)
    {
      pos += sizeof ("rumbStore\":{\"crumb\":\"");

      for (std::string::size_type i = pos; i < pos + sizeof (char) * 11; ++i)
        { out += html[i]; }
    }

  return out;
}

int
stock_crawler::YahooFinance::RetrieveUrlStepOne (FILE *html_out)
{
  CURL *curl = curl_easy_init ();

  if (curl == nullptr)
    { return -1; }

  curl_easy_setopt(curl, CURLOPT_URL, MakeUrlStepOne ().c_str ());
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, html_out);
  curl_easy_setopt(curl, CURLOPT_COOKIEJAR, temp_cookie_path_.c_str ());

  CURLcode res = curl_easy_perform (curl);

  curl_easy_cleanup (curl);
  return res;
}

int
stock_crawler::YahooFinance::RetrieveUrlStepTwo (FILE *csv_out, const std::string &crumb)
{
  CURL *curl = curl_easy_init ();

  if (curl == nullptr)
    { return -1; }

  curl_easy_setopt(curl, CURLOPT_URL, MakeUrlStepTwo (crumb).c_str ());
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, csv_out);
  curl_easy_setopt(curl, CURLOPT_COOKIEFILE, temp_cookie_path_.c_str ());

  CURLcode res = curl_easy_perform (curl);

  curl_easy_cleanup (curl);
  return res;
}
