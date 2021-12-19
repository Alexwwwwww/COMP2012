#ifndef TOY_H
#define TOY_H

#include <string>
#include "Product.h"
/* ======================================
    TODO: Complete the class declaration of Toy
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
class Toy:public Product
{
    private:
        std::string character;
        std::string manufacturer;
    public:
        Toy(double regular_price,const std::string& character, const std::string& manufacturer);
        virtual ~Toy();
        std::string get_character() const;
        std::string get_manufacturer() const;
        virtual void print() const;

};
#endif