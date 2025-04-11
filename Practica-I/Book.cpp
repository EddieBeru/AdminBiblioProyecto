//
// Created by Roy Arias on 25/3/2025.
//

#include "Book.h"

Book::Book(const std::string &title, const std::string &author, int num_pages)
      : Material(title, author),
        numPages(num_pages) {
}

int Book::get_num_pages() const {
    return numPages;
}

void Book::set_num_pages(const int num_pages) {
    numPages = num_pages;
}

std::string Book::get_type() const {
    return "Book";
}

void Book::print(std::ostream &os) const {
    os << "Libro: " << get_title() << " por " << get_author() << " con " << numPages << " paginas";
}


