//
// Created by Roy Arias on 25/3/2025.
//

#include "Material.h"

Material::Material() {
}

Material::~Material() = default;


Material::Material(const std::string &title, const std::string &author)
        : title(title),
          author(author) {
}

std::string Material::get_title() const {
    return title;
}

void Material::set_title(const std::string &title) {
    this->title = title;
}

std::string Material::get_author() const {
    return author;
}

void Material::set_author(const std::string &author) {
    this->author = author;
}

void Material::serialize(std::ostream &out) const {
    size_t  titleSize = title.size();
    size_t  authorSize = author.size();

    out.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
    out.write(title.c_str(), titleSize);

    out.write(reinterpret_cast<const char*>(&authorSize), sizeof(authorSize));
    out.write(author.c_str(), authorSize);
}

void Material::deserialize(std::istream &in) {
    size_t  titleSize;
    size_t  authorSize;

    in.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
    title.resize(titleSize);
    in.read(&title[0], titleSize);

    in.read(reinterpret_cast<char*>(&authorSize), sizeof(authorSize));
    author.resize(authorSize);
    in.read(&author[0], authorSize);

}

std::ostream& operator<<(std::ostream &os, const Material &material) {
    material.print(os);
    return os;
}
