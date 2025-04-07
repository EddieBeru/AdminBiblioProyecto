//
// Created by Roy Arias on 25/3/2025.
//

#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include "Utilities.h"

template<class T>
class FilesManager {

public:

    static void saveFiles(const T& data);
    static void openFiles();
};



#endif //FILESMANAGER_H
