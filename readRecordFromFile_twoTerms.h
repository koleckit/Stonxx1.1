/** \file readRecordFromFile_twoTerms.h
* \brief Plik nagłówkowy modułu readRecordFromFile_twoTerms.

*/
#ifndef STONXX_BETA_2_READRECORDFROMFILE_TWOTERMS_H
#define STONXX_BETA_2_READRECORDFROMFILE_TWOTERMS_H

#endif //STONXX_BETA_2_READRECORDFROMFILE_TWOTERMS_H

/** \brief Wyszukiwanie rekordu akcji.
 *
 * Funkcja wyszukuje rekord akcji na podstawie nazwy oraz daty - kombinacja tych wartości jest unikalna w pliku bazowym.
 * \param file_name nazwa pliku bazowego
 * \param search_date wyszukiwana data
 * \param search_name wyszukiwana nazwa
 * \return record_stock rekord akcji którą wyszukujemy

*/

using namespace std;

vector<string> readRecordFromFile_twoTerms(string file_name, string search_date, string search_name)
{
    vector<string> record_stock;
    ifstream file;
    file.open(file_name);

    bool found_record = false;

    string stock_date;
    string stock_name;
    string stock_price_open;
    string stock_price_close;
    string stock_price_high;
    string stock_price_low;
    string stock_price_volume;

    while(getline(file, stock_date,',') && !found_record)
    {
        getline(file, stock_name,',');
        getline(file, stock_price_open,',');
        getline(file, stock_price_close,',');
        getline(file, stock_price_high,',');
        getline(file, stock_price_low,',');
        getline(file, stock_price_volume,'\n');
        if((stock_date == search_date) && (stock_name == search_name))
        {
            found_record = true;
            record_stock.push_back(stock_date);
            record_stock.push_back(stock_name);
            record_stock.push_back(stock_price_open);
            record_stock.push_back(stock_price_close);
            record_stock.push_back(stock_price_high);
            record_stock.push_back(stock_price_low);
            record_stock.push_back(stock_price_volume);
        }
    }

    /* cout << record_stock[0] << " " << record_stock[1] << " Wartość akcji: " << record_stock[2] << "USD"; */

    return record_stock;
}