/** \file checkIsDateCorrect.h
* \brief Plik nagłówkowy modułu checkIsDateCorrect.

*/

#ifndef STONXX_BETA_2_CHECKISDATECORRECT_H
#define STONXX_BETA_2_CHECKISDATECORRECT_H

#endif //STONXX_BETA_2_CHECKISDATECORRECT_H

/** \brief Sprawdzanie poprawności dat.
 *
 * Funkcja sprawdza czy data sprzedaży akcji nastąpiła po dacie zakupu.
 * \param stock_date_bought data zakupu
 * \param stock_date_sold data sprzedaży
 * \return is_okay wartość logiczna warunku

*/
bool checkIsDateCorrect(vector<string> stock_date_bought, vector<string> stock_date_sold)
{
    string date_bought = stock_date_bought[0];
    string date_sold = stock_date_sold[0];

    bool is_okay;

    int b_year = stof(date_bought.substr(0,4));
    int b_month = stof(date_bought.substr(5, 2));
    int b_day = stof(date_bought.substr(8, 2));

    int s_year = stof(date_sold.substr(0,4));
    int s_month = stof(date_sold.substr(5, 2));
    int s_day = stof(date_sold.substr(8, 2));

    if(s_year < b_year)
    {
        is_okay = false;
    }
    if(s_year > b_year)
    {
        is_okay = true;
    }
    if(s_year == b_year)
    {
        if(s_month < b_month)
        {
            is_okay = false;
        }
        if(s_month > b_month)
        {
            is_okay = true;
        }
        if(s_month == b_month)
        {
            if(s_day > b_day)
            {
                is_okay = true;
            }
            else
            {
                is_okay = false;
            }
        }
    }
    return is_okay;
}