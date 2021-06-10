/** \file StockOnDate.h
* \brief Plik nagłówkowy modułu StockOnDate.

*/

#ifndef STONXX_BETA_2_STOCKONDATE_H
#define STONXX_BETA_2_STOCKONDATE_H

#endif //STONXX_BETA_2_STOCKONDATE_H

/** \brief Element listy dynamicznej
 *
 * Parametry danej akcji w danym dniu.
*/

using namespace std;

struct stockOnDate
{
    ///parametry kluczowe
    string stock_date;
    string stock_sell_date;
    string stock_name;
    string stock_price_open;
    string stock_price_close;
    string stock_price_high;
    string stock_price_low;
    string stock_volume;
    float stock_qty;
    float cash_in_stock;
    string transaction_type;
    int transaction_id;
    int price_sold;
    ///Wskaźnik na następny element
    stockOnDate *next;
    stockOnDate();
};

stockOnDate::stockOnDate()
{
    next = 0;
}