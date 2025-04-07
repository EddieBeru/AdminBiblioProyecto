//
// Created by Roy Arias on 25/3/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Utilities.h"

class Material {
private:
    std::string title;
    std::string author;

public:
    Material();

    Material(const std::string &title, const std::string &author);

    virtual ~Material() = 0;

    std::string get_title() const;

    void set_title(const std::string &title);

    std::string get_author() const;

    void set_author(const std::string &author);

    virtual std::string get_type() const = 0;

    virtual void print(std::ostream &os) const = 0;

    virtual  void serialize(std::ostream &out) const;

    virtual void deserialize(std::istream &in);

    friend std::ostream& operator<<(std::ostream &os, const Material &material);

};



#endif //MATERIAL_H
