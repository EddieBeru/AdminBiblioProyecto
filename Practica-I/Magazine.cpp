//
// Created by Roy Arias on 25/3/2025.
//

#include "Magazine.h"

Magazine::Magazine() {
}

Magazine::~Magazine() {

}

Magazine::Magazine(const std::string &title, const std::string &author, const int edit_num)
        : Material(title, author),
          editNum(edit_num) {
}

int Magazine::get_edit_num() const {
    return editNum;
}

void Magazine::set_edit_num(const int edit_num) {
    editNum = edit_num;
}

std::string Magazine::get_type() const {
    return "Magazine";
}

void Magazine::print(std::ostream &os) const {
    os << "Revista: " << get_title() << " por " << get_author() << " edicion: " << editNum << std::endl;
}

void Magazine::serialize(std::ostream &out) const {
    Material::serialize(out);

    out.write(reinterpret_cast<const char *>(&editNum), sizeof(editNum));
}

void Magazine::deserialize(std::istream &in) {
    Material::deserialize(in);

    in.read(reinterpret_cast<char *>(&editNum), sizeof(editNum));
}

