cmake_minimum_required(VERSION 3.1)
project(stock_crawler)

set(CMAKE_CXX_STANDARD 14)
find_package(CURL REQUIRED)

set(RETRIEVE_DATA_SRC src/RetrieveData.hpp src/RetrieveData.cpp src/RetrieveDataInterface.hpp)
set(YAHOO_FINANCE_SRC src/yahoo_finance/YahooFinance.hpp src/yahoo_finance/YahooFinance.cpp)
set(EXAMPLE_YAHOO_FINANCE examples/yahoo_finance.cpp)
set(EXAMPLE_YAHOO_FINANCE_LIST_BATCH examples/yahoo_finance_list_batch.cpp)

add_executable(example_yahoo_finance ${YAHOO_FINANCE_SRC} ${RETRIEVE_DATA_SRC} ${EXAMPLE_YAHOO_FINANCE})
target_link_libraries(example_yahoo_finance ${CURL_LIBRARIES})

add_executable(example_yahoo_finance_list_batch ${YAHOO_FINANCE_SRC} ${RETRIEVE_DATA_SRC} ${EXAMPLE_YAHOO_FINANCE_LIST_BATCH})
target_link_libraries(example_yahoo_finance_list_batch ${CURL_LIBRARIES})
