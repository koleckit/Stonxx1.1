#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "readRecordFromFile_twoTerms.h"
#include "profitCalc.h"
#include "investmentsCostCalc.h"
#include "checkIsDateCorrect.h"
#include "roiCalc.h"

#include "StockOnDate.h"
#include "Portfolio.h"

/**
 *\mainpage
 *\par Stonxx
 * Prosty tracker portfela inwestycyjnego dla akcji z grupy Big Five oraz indeksu NASDAQ Composite.
 * (Apple [AAPL], Amazon [AMZN], Google [GOOGL], Microsoft [MSFT], Facebook [FB])
 *\author Tycjan Kołecki:
 *\par Kontakt:
 * \a tycjan.kolecki.stud@pw.edu.pl
 * \Github:
 * \a koleckit
*/


using namespace std;

int main()
{
    cout << "Stonxx beta" << endl;
    cout << "-------------------------------------------" << endl;
    int main_menu;

    do {
        cout << "Szybkie wyszukanie wartości akcji w określonym dniu - 1" << endl;
        cout << "Szybka kalkulacja profitu - 2" << endl;
        cout << "Twoje portfolio inwestycyjne - 3" << endl;
        cout << "Zakończ prace - 4" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Wybór: ";
        cin >> main_menu;
        cout << "-------------------------------------------" << endl;

        if (main_menu == 1) {
            cout << "Podaj datę [YYYY-MM-DD]: ";
            string search_date;
            cin >> search_date;

            cout << "Podaj symbol akcji: ";
            string search_name;
            cin >> search_name;

            vector<string> stock_data = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date, search_name);

            cout << "-------------------------------------------" << endl;
            cout << "Data: " << stock_data[0] << endl;
            cout << "Symbol akcji: " << stock_data[1] << endl;
            cout << "Cena na otwarciu: " << stock_data[2] << "$" << endl;
            cout << "Cena na zamknięciu: " << stock_data[3] << "$" << endl;
            cout << "Najwyższa cena w dniu: " << stock_data[4] << "$" << endl;
            cout << "Najniższa cena w dniu: " << stock_data[5] << "$" << endl;
            cout << "Wolium w danym dniu: " << stock_data[6] << "$" << endl;
            cout << "-------------------------------------------" << endl;
        }

        if (main_menu == 2) {
            cout << "Podaj symbol akcji: ";
            string search_name;
            cin >> search_name;

            cout << "Podaj ilość zakupionych akcji (całość lub część): ";
            float stock_quantity;
            cin >> stock_quantity;


            cout << "Podaj datę zakupu akcji [YYYY-MM-DD]: ";
            string search_date_buy;
            cin >> search_date_buy;
            vector<string> stock_bought = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date_buy, search_name);

            cout << "Podaj datę sprzedaży akcji [YYYY-MM-DD]: ";
            string search_date_sell;
            cin >> search_date_sell;
            vector<string> stock_sold = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date_sell, search_name);

            cout << "-------------------------------------------" << endl;

            bool test = checkIsDateCorrect(stock_bought, stock_sold);

            if (test == 1) {
                float profit_calc = profitCalc(stock_bought, stock_sold, stock_quantity);
                float investments_cost = investmentCostCalc(stock_bought, stock_quantity);
                float roi = roiCalc(profit_calc, investments_cost);

                if (profit_calc > 0) {
                    cout << "Na tranzakcji zarobiłeś: " << profit_calc << "$";
                }
                if (profit_calc < 0) {
                    cout << "Na tranzakcji straciłeś: " << profit_calc << "$";
                }
                if (profit_calc == 0) {
                    cout << "Wyszedłeś na zero";
                }
                cout << endl;
                cout << "Zainwestowałeś: " << investments_cost << "$" << endl;
                cout << "Osiągnąłeś stopę zwrotu: " << roi << "%" << endl;
                cout << "-------------------------------------------" << endl;
            } else {
                cout << "Zostały podanie nieprawidłowe daty!";
            }
        }

        if (main_menu == 3) {
            int portfolio_menu;
            portfolio *portfolio_base = new portfolio;
            int id = 1;

            do {
                cout << "Kreator portfolio inwestycyjnego" << endl;
                cout << "Dodaj tranzakcje - 1" << endl;
                cout << "Usuń tranzakcje - 2" << endl;
                cout << "Pokaż tranzakcje - 3" << endl;
                cout << "Pokaż podsumowanie finansowe - 4" << endl;
                cout << "Generuj raport PDF z tranzakcji - 5" << endl;
                cout << "Powrót - 6" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Wybór: ";
                cin >> portfolio_menu;
                cout << "-------------------------------------------" << endl;

                if (portfolio_menu == 1) {
                    int add_more_portfolio;

                    int add_portfolio_menu;
                    float stock_quantity;

                    int stock_price_sold;

                    bool is_sold_portfolio;
                    bool test_portfolio;

                    string search_name;
                    string trans;
                    string search_date_buy;
                    string search_date_sold;
                    string stock_date_sold;

                    //vector<string> stock_bought;

                    int add_more;

                    do {
                        cout << "Tranzakcja zakupu - 1" << endl;
                        cout << "Tranzakcja sprzedaży - 2" << endl;
                        cout << "-------------------------------------------" << endl;
                        cout << "Wybór: ";
                        cin >> add_portfolio_menu;
                        cout << "-------------------------------------------" << endl;
                        cout << "Podaj symbol akcji: ";
                        cin >> search_name;
                        cout << "Podaj datę zakupu akcji [YYYY-MM-DD]: ";
                        cin >> search_date_buy;

                        vector<string> stock_bought = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date_buy, search_name);

                        if (add_portfolio_menu == 1) {
                            cout << "Podaj ilość zakupionych akcji (całość lub część): ";
                            cin >> stock_quantity;
                            trans = "Zakup";

                            test_portfolio = true;
                        }

                        if (add_portfolio_menu == 2) {
                            cout << "Podaj datę sprzedaży akcji [YYYY-MM-DD]: ";
                            cin >> search_date_sold;
                            trans = "Sprzedaż";

                            //vector<string> stock_bought = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date_buy, search_name);
                            vector<string> stock_sold = readRecordFromFile_twoTerms("Akcje_beta.txt", search_date_sold, search_name);

                            stock_date_sold = stock_sold[0];
                            stock_price_sold = stof(stock_sold[3]);

                            cout << "Podaj ilość sprzedanych akcji (całość lub część): ";
                            cin >> stock_quantity;

                            test_portfolio = checkIsDateCorrect(stock_bought, stock_sold);

                            if (test_portfolio == false)
                            {
                                cout << "Wprowadzone złe daty!" << endl;
                            }
                        }

                        int trans_id = id;

                        if(test_portfolio == true)
                        {
                            portfolio_base->addStockToPortfolio(stock_bought, stock_date_sold, stock_price_sold, stock_quantity, trans, trans_id);
                        }

                        id++;

                        cout << "Czy chcesz dodać więcej transakcji? Tak-1 / Powrót-2: ";
                        cin >> add_more;
                        cout << "-------------------------------------------" << endl;

                    } while (add_more == 1 && test_portfolio == true);
                }

                if (portfolio_menu == 2) {
                    int id_del;
                    if (id == 1) {
                        cout << "Brak transakcji!" << endl;
                        cout << "-------------------------------------------" << endl;
                    }
                    if (id > 1) {
                        id--;
                        cout << "Podaj numer transakcji (od 1 do " << id << "), który chcesz usunąć: ";
                        cin >> id_del;
                        portfolio_base->delStockFromPortfolio(id_del);
                        cout << "Usunięto! Jeśli chcesz zobaczyć zmiany w .txt," << endl;
                        cout << "wygeneruj go ponownie." << endl;
                        cout << "-------------------------------------------" << endl;
                    }
                }

                if (portfolio_menu == 3) {
                    if (id == 1) {
                        cout << "Brak transakcji!" << endl;
                        cout << "-------------------------------------------" << endl;
                    }
                    if (id > 1) {
                        portfolio_base->showPortfolio();
                        cout << "-------------------------------------------" << endl;
                    }
                }

                if (portfolio_menu == 4)
                {
                    portfolio_base->calculateAssets();
                }

                if (portfolio_menu == 5) {
                    if (id == 1) {
                        cout << "Brak transakcji!" << endl;
                        cout << "-------------------------------------------" << endl;
                    }
                    if (id > 1) {
                        portfolio_base->generatePortfolioReport();
                        cout << "Wygenerowano raport .txt!" << endl;
                        cout << "-------------------------------------------" << endl;
                    }
                }
            } while (portfolio_menu != 6);
        }
    } while(main_menu != 4);

    cout << "Do zobaczenia!";
    return 0;
}


