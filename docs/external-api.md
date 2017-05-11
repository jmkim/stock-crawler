# External API

## Classes

### RetrieveData ([`src/RetrieveData.hpp`]( ../src/RetrieveData.hpp ))
#### RetrieveDataFromYahooFinance(std::string&,std::string&,std::string&,std::string&,std::string&,std::string&)
```c
int stock_crawler::RetrieveDataFromYahooFinance (
    const std::string &stock_item,
    const std::string &period_start,
    const std::string &period_end,
    const std::string &period_interval  = "1d",
    const std::string &out_csv_path     = "./csv/result.csv",
    const std::string &temp_dir_path    = "./temp"
)
```
- Return value
    - `99` if cannot access to the temp file path.
    - `101 ~ 193` if error while step 1 (html download for extracting CrumbStore).
    - `199` if cannot access to the CSV file path.
    - `201 ~ 293` if error while step 2 (csv file downloading).
    - Otherwise `0`.

#### RetrieveDataFromYahooFinance(std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&)
```c
int stock_crawler::RetrieveDataFromYahooFinance (
    const std::string &stock_item,
    const std::string &period_start,
    const std::string &period_end,
    const std::string &period_interval,
    const std::string &out_csv_path,
    const std::string &temp_cookie_path,
    const std::string &temp_html_path
)
```
- Return value
    - `99` if cannot access to the temp file path.
    - `101 ~ 193` if error while step 1 (html download for extracting CrumbStore).
    - `199` if cannot access to the CSV file path.
    - `201 ~ 293` if error while step 2 (csv file downloading).
    - Otherwise `0`.

