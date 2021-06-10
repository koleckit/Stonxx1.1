/** \file investmentsCostCalc.h
* \brief Plik nagłówkowy modułu investmentsCostCalc.

*/
#ifndef STONXX_BETA_2_INVESTMENTSCOSTCALC_H
#define STONXX_BETA_2_INVESTMENTSCOSTCALC_H

#endif //STONXX_BETA_2_INVESTMENTSCOSTCALC_H

/** \brief Kalkulacja kosztów inwestycyjnych.
 *
 * Funkcja oblicza całkowity koszt inwestycji w zakup określonej liczby (także fragmentów) akcji.
 * \param stock_bought rekord akcji w danym dniu
 * \param quantum liczba akcji
 * \return investments_cost kwota inwestycji

*/

auto investmentCostCalc(vector<string> stock_bought, float quantum)
{
    float stock_bought_price = stof(stock_bought[3]);
    float investments_cost = stock_bought_price * quantum;

    return investments_cost;
}

