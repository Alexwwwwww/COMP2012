#include <iostream>
#include "Product.h"
#include "Book.h"
#include "Toy.h"
using namespace std;
#include <string>

Product::Product(double regular_price)//:regular_price(regular_price)
{
    this->regular_price=regular_price;
}

Product::~Product() {
    cout <<"Product destructed" <<endl;
}

// TODO: complete Product::get_regular_price
double Product::get_regular_price() const {
    return regular_price;
}
// TODO: complete Product::get_retail_price
double Product::get_retail_price() const{
    return regular_price;
}

void Product::print() const {
    cout<<"Product: "<<endl;
    cout<<"Price: "<<get_retail_price()<<endl; 
}

Book::Book(double regular_price, const string& title, const string& genre, const string& publisher, double discount):
Product(regular_price)/*,title(title),genre(genre),publisher(publisher),discount(discount)*/
{
    this->title=title;
    this->genre=genre;
    this->publisher=publisher;
    this->discount=discount;
}
Book::~Book() {
    cout << "Book destructed" <<endl;
}
// TODO: complete Book::get_title
string Book::get_title() const{
    return title;
}
// TODO: complete Book::get_genre
string Book::get_genre() const{
    return genre;
}
// TODO: complete Book::get_publisher
string Book::get_publisher() const{
    return publisher;
}
// TODO: complete Book::get_discount
double Book::get_discount() const {
    return discount;
}
// TODO: complete Book::get_retail_price
double Book::get_retail_price() const {
    return get_regular_price()*discount;
}
void Book::print() const{
    cout<<"Book: "<<endl;
    cout << "Title: "<<get_title() << ", Genre: " <<get_genre() << ", Publisher: " << get_publisher() << ", Retail Price: " << get_retail_price()<<endl;
}


Toy::Toy(double regular_price,const string& character, const string& manufacturer): 
Product(regular_price)/*,character(character),manufacturer(manufacturer)*/
{
    this->character=character;
    this->manufacturer=manufacturer;
}
Toy::~Toy() {
    cout<<"Toy destructed"<<endl;
}
// TODO: complete Toy::get_character
string Toy::get_character() const {
    return character;
}
// TODO: complete Toy::get_manufacturer
string Toy::get_manufacturer() const {
    return manufacturer;
}
void Toy::print() const {
    cout<<"Toy: "<<endl;
    cout << "Character: "<<get_character() << ", Manufacturer: " <<get_manufacturer() << ", Retail Price: " << get_retail_price()<<endl;
}

int main()
{
    Product* p1 = new Product(164.3);
    Product p2(243.3);
    Product* b1 = new Book(200.0, "Book 1", "Fiction", "ABC publisher", 0.8);
    Product p3 = *b1;
    Product* t1 = new Toy(105.4, "Unicorn", "CCC Manufacturer");
    Product p4 = *t1;
    p1->print();
    p2.print();
    b1->print();
    p3.print();
    t1->print();
    p4.print();
    cout << "Total Price: "<<endl;
    cout << p1->get_retail_price() + p2.get_retail_price() + b1->get_retail_price() + p3.get_retail_price() + t1->get_retail_price() + p4.get_retail_price()<<endl;
    delete p1;
    delete b1;
    delete t1;
}