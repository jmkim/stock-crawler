# Get started

## Index
1. [How to build]( #how-to-build )
2. [How to use]( #how-to-use )

## How to build
Universal Stock Crawler requires `libcurl4-dev` and `cmake`.
```bash
$ sudo apt install libcurl4-openssl-dev cmake
```

Download the source.
```bash
$ wget https://github.com/kdzlvaids/stock-crawler/archive/master.zip
```

Extract the source.
```bash
$ unzip master.zip
```

Build the source.
```bash
$ cd ./stock-crawler-master
$ cmake .
```

## How to use
All classes derive from the interface named `RetrieveDataInterface`.
You can use the [internal API]( internal-api.md ) by yourself with your detailed settings,
or use the well-defined macro-like [external API]( external-api.md ) functions named starting with `RetrieveDataFrom`.

### YahooFinance
You can retrieve all kinds of stock data from YahooFinance with one function.

Following example is retrieving the [NASDAQ Composite stock data from Yahoo Finance]( https://finance.yahoo.com/quote/%5EIXIC ).
```c
/*
    Retrieve the NASDAQ Composite (^IXIC) stock data from Yahoo Finance
    between 2014-05-08 and 2017-05-05 with interval 1 day.
*/
stock_crawler::RetrieveDataFromYahooFinance ("^IXIC", "1399474800", "1494169200", "1d");
```
For more information, see the [API documentation]( external-api.md#retrievedatafromyahoofinancestdstringstdstringstdstringstdstringstdstringstdstring ).

#### Examples
- [`examples/yahoo_finance.cpp`]( ../examples/yahoo_finance.cpp )
- [`examples/yahoo_finance_list_batch.cpp`]( ../examples/yahoo_finance_list_batch.cpp )

#### References
- [YahooFinance]( https://finance.yahoo.com )

