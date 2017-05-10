cmake_minimum_required(VERSION 3.7)
project(stock_crawler)

set(CMAKE_CXX_STANDARD 14)
find_package(CURL REQUIRED)

set(RETRIEVE_DATA_SRC src/RetrieveData.hpp src/RetrieveData.cpp src/RetrieveDataInterface.hpp)
set(YAHOO_FINANCE_SRC src/yahoo_finance/YahooFinance.hpp src/yahoo_finance/YahooFinance.cpp)
set(EXAMPLE_SRC examples/yahoo_finance.cpp)

add_executable(stock_crawler ${YAHOO_FINANCE_SRC} ${RETRIEVE_DATA_SRC} ${EXAMPLE_SRC})
target_link_libraries(stock_crawler ${CURL_LIBRARIES})