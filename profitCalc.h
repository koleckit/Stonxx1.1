/** \file profitCalc.h
* \brief Plik nagłówkowy modułu profitCalc.

*/
#ifndef STONXX_BETA_2_PROFITCALC_H
#define STONXX_BETA_2_PROFITCALC_H

#endif //STONXX_BETA_2_PROFITCALC_H

/** \brief Kalkulacja kwoty zwrotu z inwestycji.
 *
 * Funkcja oblicza zwrot z inwestycji na podstawnie daty zakupu oraz sprzedaży.
 * \param stock_bought rekord akcji w dniu zakupu
 * \param stock_sold rekord akcji w dniu sprzedaży
 * \return profit kwota zwrotu

*/

auto profitCalc(vector<string> stock_bought, vector<string> stock_sold, float quantum)
{
    float stock_bought_price = stof(stock_bought[3]);
    float stock_sold_price = stof(stock_sold[3]);

    float total_stock_bought_price = stock_bought_price * quantum;
    float total_stock_sold_price = stock_sold_price * quantum;

    float profit = total_stock_sold_price - total_stock_bought_price;

    return profit;
}