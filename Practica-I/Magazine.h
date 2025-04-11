//
// Created by Roy Arias on 25/3/2025.
//

#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <ostream>

#include "Material.h"

class Magazine: public Material {
private:
    int editNum;

public:

    Magazine();

    Magazine(const std::string &title, const std::string &author, const int edit_num);

    ~Magazine();

    int get_edit_num() const;

    void set_edit_num(const int edit_num);

    void print(std::ostream &os) const override;

    void serialize(std::ostream &out) const override;

    void deserialize(std::istream &in) override;

    std::string get_type() const override;

};



#endif //MAGAZINE_H
