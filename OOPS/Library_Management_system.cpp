#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Library {
private:
    map<string, int> available_books = {{"Hindi", 20}, {"English", 30}, {"Mathematics", 45}, {"Social Science", 25}, {"Punjabi", 42}, {"Sanskrit", 25}, {"AI-ML", 130}, {"Probability", 85}};
    int capital = 500;
    int my_budget = 0;
    unordered_set<string> purchased_books_set;
    vector<string> purchased_books_list;
    map<string, int> purchased_book_debt;
    int num_purchased_books = 0;
    int num_sold_books = 0;
    int purchased_debt = 0;
    int sold_debt = 0;
public:
    Library (int budget) : my_budget(budget) {};
    void buy_book(string book_name) {
        if(purchased_books_set.count(book_name)) return;
        if(available_books.find(book_name) == available_books.end()) return;
        purchased_books_set.insert(book_name);
        purchased_books_list.push_back(book_name);
        auto it = available_books.find(book_name);
        int price = it->second;
        if(price >= sold_debt) {
            price = price - sold_debt;
            sold_debt = 0;
        }
        else {
            sold_debt = sold_debt - price;
            price = 0;
        }
        if(my_budget >= price) {
            my_budget -= price;
            capital += price;
            purchased_book_debt.insert({book_name, 0});
        }
        else {
            purchased_debt += price - my_budget;
            capital += my_budget;
            purchased_book_debt.insert({book_name, price - my_budget});
            my_budget = 0;
        }
        num_purchased_books++;
    }
    void return_book(string book_name) {
        if(!purchased_books_set.count(book_name)) return;
        purchased_books_set.erase(book_name);
        auto it1 = find(purchased_books_list.begin(), purchased_books_list.end(), book_name);
        purchased_books_list.erase(it1);
        auto it2 = purchased_book_debt.find(book_name);
        int real_price = available_books.find(book_name)->second;
        if(real_price >= purchased_debt) {
            real_price -= purchased_debt;
            purchased_debt = 0;
        }
        else {
            purchased_debt -= real_price;
            real_price = 0;
        }
        purchased_book_debt.erase(it2);
        if(capital >= real_price) {
            capital -= real_price;
            my_budget += real_price;
        }
        else {
            sold_debt += real_price - capital;
            my_budget += capital;
            capital = 0;
        }
        num_purchased_books--;
    }
    void sell_book(string book_name, int price) {
        if(available_books.find(book_name) != available_books.end()) return;
        available_books.insert({book_name, price});
        if(price >= purchased_debt) {
            price = price - purchased_debt;
            purchased_debt = 0;
        }
        else {
            purchased_debt -= price;
            price = 0;
        }
        if(capital >= price) {
            capital -= price;
            my_budget += price;
        }
        else {
            sold_debt += price - capital;
            my_budget += capital;
            capital = 0;
        }
        num_sold_books++;
    }
    int nums_books_purchased() {
        return num_purchased_books;
    }
    int nums_books_sold() {
        return num_sold_books;
    }
    int debt_to_library() {
        return purchased_debt;
    }
    int debt_to_me() {
        return sold_debt;   
    }
    int budget_my() {
        return my_budget;
    }
    int capital_their() {
        return capital;
    }
    vector<string> books_purchased_list() {
        return purchased_books_list;
    }
    map<string, int> books_to_debt_list() {
        return purchased_book_debt;
    }
    map<string, int> books_available() {
        return available_books;
    }
};

int main() {
    Library Kunal(100);
    // Kunal.buy_book("Hindi");
    // Kunal.buy_book("AI-ML");
    // Kunal.sell_book("History", 50);
    // Kunal.return_book("AI-ML");
    // Kunal.sell_book("RD Sharma", 700);
    // Kunal.buy_book("English");
    // Kunal.return_book("Hindi");
    // Kunal.return_book("English");



    cout << "Books Puchased -> " << Kunal.nums_books_purchased() << endl;
    cout << "Books Sold -> " << Kunal.nums_books_sold() << endl;
    cout << "My Debt to Library -> " << Kunal.debt_to_library() << endl;
    cout << "Library's Debt to me -> " << Kunal.debt_to_me() << endl;
    cout << "Budget -> " << Kunal.budget_my() << endl;
    cout << "Capital -> " << Kunal.capital_their() << endl;
    vector<string> list = Kunal.books_purchased_list();
    for(auto i: list) {
        cout << i << " ";
    }
    cout << endl;
    map<string, int> myMap = Kunal.books_to_debt_list();
    for(auto i: myMap) {
        cout << "{" << i.first << ", " << i.second << "} "; 
    }
    cout << endl;
    myMap = Kunal.books_available();
    for(auto i: myMap) {
        cout << "{" << i.first << ", " << i.second << "} "; 
    }
    cout << endl << endl;
}