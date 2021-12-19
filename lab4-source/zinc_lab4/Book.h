#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Product.h"
/* ======================================
    TODO: Complete the class declaration of Book
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
class Book : public Product
{
private:
    std::string title;
    std::string genre;
    std::string publisher;
    double discount;

public:
    Book(double regular_price, const std::string &title, const std::string &genre, const std::string &publisher, double discount);
    virtual ~Book();
    
    std::string get_title() const;
    std::string get_genre() const;
    std::string get_publisher() const;

    double get_discount() const;
    virtual double get_retail_price() const;
    virtual void print() const;
};
#endif