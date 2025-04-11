#include <iostream>
#include "Book.h"
#include "Magazine.h"
#include "FilesManager.cpp"


int main() {
    Magazine *magazine1 = new Magazine("Revista 1", "Autor 1", 1);

   //std::cout<< *magazine1 << std::endl;

    FilesManager<Magazine>::saveFiles(*magazine1);

    FilesManager<Magazine>::openFiles();

    delete magazine1;

    return 0;
}