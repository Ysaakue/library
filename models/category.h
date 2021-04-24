#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <qdebug.h>
#include "database.h"

namespace library{
namespace models {
class Category : public Database {
private:
    int id;
    QString description;

public:
    Category();

    // Getters
    int getId(){ return this->id; }
    QString getDescription(){ return this->description; }

    // Setters
    void setId(int id){ this->id = id; }
    void setDescription(QString description){ this->description = description; }

    // Manage database table
    static bool createTable();
    static bool dropTable();
    static bool clearTable();

    // Crud
    bool save();
    bool update();
    bool destroy();
};}}

#endif // CATEGORY_H
