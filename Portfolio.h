/** \file Portfolio.h
* \brief Plik nagłówkowy modułu Portfolio.

*/

#ifndef STONXX_BETA_2_PORTFOLIO_H
#define STONXX_BETA_2_PORTFOLIO_H

#endif //STONXX_BETA_2_PORTFOLIO_H

/** \brief Lista dynamiczna
 *
 * Portfolio inwestycyjne zawierające nasze akcje.
*/


using namespace std;

struct portfolio
{
    stockOnDate *first;
    void addStockToPortfolio(vector<string> portfolio_stock, string stock_date_sold, float price_sold, float qty, string transtation, int trans_id);
    void delStockFromPortfolio(int id);
    void showPortfolio();
    void generatePortfolioReport();
    void calculateAssets();
    portfolio();
};

portfolio::portfolio()
{
    first = 0; //konstruktor
}

void portfolio::addStockToPortfolio(vector<string> portfolio_stock, string stock_date_sold, float price_sold, float qty, string transaction, int trans_id)
{
    stockOnDate *new_stock = new stockOnDate;

    new_stock->stock_date = portfolio_stock[0];
    new_stock->stock_name = portfolio_stock[1];
    new_stock->stock_price_open = portfolio_stock[2];
    new_stock->stock_price_close = portfolio_stock[3];
    new_stock->stock_price_high = portfolio_stock[4];
    new_stock->stock_price_low = portfolio_stock[5];
    new_stock->stock_volume = portfolio_stock[6];
    new_stock->stock_qty = qty;
    new_stock->cash_in_stock = qty*stof(portfolio_stock[3]);

    new_stock->transaction_type = transaction;

    new_stock->stock_sell_date = stock_date_sold;
    new_stock->price_sold = price_sold;

    new_stock->transaction_id = trans_id;

    if(first==0)
    {
        first = new_stock;
    }
    else
    {
        stockOnDate *temp = first;

        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next=new_stock;
        new_stock->next = 0;
    }
}

void portfolio::showPortfolio()
{
    stockOnDate *temp = first;
    while(temp)
    {
        cout << "--------------------------" << endl;
        cout<< "Numer tranzakcji: " << temp->transaction_id << endl;
        cout << "Typ transakcji: " << temp->transaction_type << endl;
        cout << "Data zakupu: " << temp->stock_date << endl;
        if(temp->transaction_type == "Sprzedaż")
        {
            cout << "Data sprzedaży: " << temp->stock_sell_date << endl;
        }
        cout << "Nazwa: " << temp->stock_name << endl;
        cout << "Cena zakupu: " << temp->stock_price_close << "$" << endl;
        if(temp->transaction_type == "Zakup")
        {
            cout << "Ilość zakupionych akcji: " << temp->stock_qty << endl;
            cout << "Wartość akcji w portfelu: " << temp->cash_in_stock << "$" << endl;
        }
        if(temp->transaction_type == "Sprzedaż")
        {
            cout << "Cena sprzedaży: " << temp->price_sold << "$" << endl;
            cout << "Ilość sprzedanych akcji: " << temp->stock_qty << endl;
            cout << "Kwota sprzedaży: " << (temp->stock_qty * temp->price_sold) << "$" << endl;
        }

        cout << "--------------------------" << endl;

        temp=temp->next;
    };
}

void portfolio::generatePortfolioReport()
{
    ofstream txtreport("Raport.txt");
    txtreport << "Stonxx 1.0" << endl;
    txtreport << "Podsumowanie Twojego koszyka inwestycyjnego" << endl;
    txtreport << "--------------------------";
    txtreport << endl;

    stockOnDate *temp = first;
    while(temp)
    {
        txtreport << "Numer tranzakcji: " << temp->transaction_id << endl;
        txtreport << "Typ transakcji: " << temp->transaction_type << endl;
        txtreport << "Nazwa: " << temp->stock_name << endl;
        txtreport << "Data zakupu: " << temp->stock_date << endl;
        if(temp->transaction_type == "Sprzedaż")
        {
            txtreport << "Data sprzedaży: " << temp->stock_sell_date << endl;
        }
        txtreport << "Cena zakupu: " << temp->stock_price_close << "$" << endl;
        txtreport << "Ilość zakupionych akcji: " << temp->stock_qty << endl;

        if(temp->transaction_type == "Sprzedaż")
        {
            txtreport << "Ilość sprzedanych akcji: " << temp->stock_qty << endl;
            txtreport << "Cena sprzedaży: " << temp->price_sold << "$" << endl;
            txtreport << "Kwota sprzedaży: " << (temp->stock_qty * temp->price_sold) << endl;
        }
        if(temp->transaction_type == "Zakup")
        {
            txtreport << "Wartość akcji w portfelu: " << temp->cash_in_stock << "$" << endl;
        }

        txtreport << "--------------------------" << endl;

        temp=temp->next;
    };
}

void portfolio::delStockFromPortfolio(int id)
{
    if (id == 1)
    {
        stockOnDate *temp = first;
        first = temp-> next;
        delete temp;
    }
    else if (id >= 2)
    {
        int j = 1;

        stockOnDate *temp = first;

        while (temp)
        {
            if ((j+1) == id)
            {
                break;
            }
            temp = temp->next;
            j++;
        }
        if (temp->next->next==0)
        {
            delete temp->next;
            temp->next = 0;
        }
        else
        {
            stockOnDate *del = temp->next;
            temp->next= temp->next->next;
            delete del;
        }
    }
}

void portfolio::calculateAssets()
{
    float cash = 0;
    float cash_in_stocks = 0;

    stockOnDate *temp = first;
    while(temp)
    {
        if(temp->transaction_type == "Sprzedaż")
        {
            cash = cash + ((temp->stock_qty * stof(temp->stock_price_close)) - (temp->stock_qty * temp->price_sold));
        }
        if(temp->transaction_type == "Zakup")
        {
            cash_in_stocks = cash_in_stocks + (stof(temp->stock_price_close)*temp->stock_qty);
        }
        temp=temp->next;
    };
    cout << "Stan na dzień 2019-08-21: " << endl;
    cout << "Na tranzakcjach zarobiłeś: " << cash << "$" << endl;
    cout << "W swoim portfolio posiadasz akcje o wartości: " << cash_in_stocks << "$" << endl;
    cout << "-------------------------------------------" << endl;

}