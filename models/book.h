#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <qdebug.h>
#include "database.h"

namespace library{
namespace models {
class Book : public Database {
private:
    QString isbn; // primary key
    QString name;
    QString author;
    int category_id;

public:
    Book();

    // Getters
    QString getName(){ return this->name; }
    QString getAuthor(){ return this->author; }
    QString getIsbn(){ return this->isbn; }

    // Setter
    void setName(QString name){ this->name = name; }
    void setAuthor(QString author){ this->author= author; }
    void setIsbn(QString isbn){ this->isbn= isbn; }

    // Manage database table
    static bool createTable();
    static bool dropTable();
    static bool clearTable();

    // Crud
    bool save();
    bool update();
    bool destroy();
};}}

#endif // BOOK_H
