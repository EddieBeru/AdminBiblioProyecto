//
// Created by Roy Arias on 25/3/2025.
//

#ifndef BOOK_H
#define BOOK_H

#include "Material.h"

class Book: public Material {
private:
    int numPages;

public:
    Book(const std::string &title, const std::string &author, int num_pages);

    int get_num_pages() const;

    void set_num_pages(const int num_pages);

    std::string get_type() const override;

    void print(std::ostream &os) const override;

};



#endif //BOOK_H
