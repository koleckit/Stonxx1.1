/** \file roiCalc.h
* \brief Plik nagłówkowy modułu roiCalc.

*/
#ifndef STONXX_BETA_2_ROICALC_H
#define STONXX_BETA_2_ROICALC_H

#endif //STONXX_BETA_2_ROICALC_H

/** \brief Kalkulacja story zwrotu z inwestycji.
 *
 * Funkcja oblicza stopę zwrotu z inwestycji na podstawie kwoty zwrotu oraz kosztów inwestycyjnych.
 * \param profit_generate kwota zarobiona na transakcji
 * \param stock_sold kwota zainwestowana w transakcje
 * \return roi_percent stopa zwrotu wyrażona w procentach

*/

auto roiCalc(float profit_generate, float investment_coast)
{
    float roi, roi_percent;
    roi=(profit_generate/investment_coast);
    roi_percent = roi*100;

    return roi_percent;
}