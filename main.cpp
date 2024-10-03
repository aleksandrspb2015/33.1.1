#include <iostream>
#include<exception>
#include<map>
#include<string>
#include <memory>
//#include <typeinfo>
int checkInt();
class onlineMarket1{
    std::map <std::string,int> base;
    std::map<std::string,int> basket;
public:
    void setBase() {
        std::string article;
        int count;
        while (true) {
            std::cout << "Enter article and count of product(for exit enter 0): ";
            std::cin >> article;
            if (article == "0")
                break;
            else
                count = checkInt();
            base[article] = count;
        }
    }

    void getBase() {
        if(base.empty())
            std::cout<<"There is no product in the store\n";
        std::cout <<"Products: ";
        for (const auto &[article, count]: base) {
            std::cout << article <<"-"<<count<<", ";
        }
        std::cout<<std::endl;
    }

    void getBasket() {
        if (basket.empty())
            std::cout << "Basket is empty\n";
        else {
            for (const auto &[article, count]: basket) {
                std::cout << article << " " << count << std::endl;
            }
        }
    }

    void add() {
        std::string article;
        int count;
        while (true) {
            std::cout << "Enter article and count of product for add to basket: ";
            std::cin >> article;
            if (article == "0")
                break;
            else {
                count=checkInt();
                try {
                    if (base.count(article) != 1)
                        throw std::invalid_argument("Article is not at shop base!\n");
                    if (base[article] < count)
                        throw std::invalid_argument(
                                "The quantity of the product is more than in the store's database\n");
                    basket[article] = count;
                }
                catch (std::exception &ex) {
                    std::cerr << ex.what();
                }
            }
        }
    }
    void remove() {
        std::string article;
        int count;
        while (true) {
            std::cout << "Enter article and count of product for remove from basket: ";
            std::cin >> article;
            if (article == "0")
                break;
            else {
                count = checkInt();
                try {
                    if (basket.count(article) != 1)
                        throw std::invalid_argument("Article is not at basket!\n");
                    if (basket[article] < count)
                        throw std::invalid_argument("The quantity of the product is more than in basket\n");
                    basket[article] -= count;
                    if (basket[article] == 0)
                        basket.erase(article);
                }
                catch (std::exception &ex) {
                    std::cerr << ex.what();
                }
            }
        }
    }
};
int checkInt() {
    std::cin.exceptions(std::cin.failbit|std::cin.badbit);
    try {
        int value;
        std::cin >> value;
        return value;
    }

    catch (const std::ios_base::failure exception) {

        std::cout << "Error\n" << exception.what() << " \n" << exception.code() << std::endl;
        std::cin.clear();
        std::cin.ignore(10, '\n');
        std::cout<<"enter data again: ";
       return checkInt();
    }
}


int main() {
    onlineMarket1 marketMega;
    marketMega.setBase();
    marketMega.getBase();
    marketMega.add();
    marketMega.getBasket();
    marketMega.remove();
    marketMega.getBasket();
    std::cout<<"enter date in main\n";
    return 0;
}

