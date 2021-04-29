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
    Book(QString isbn, QString name, QString author, int category);

    // Getters
    QString getName(){ return this->name; }
    QString getAuthor(){ return this->author; }
    QString getIsbn(){ return this->isbn; }
    int getCategoryId(){ return this->category_id; }

    // Setter
    void setName(QString name){ this->name = name; }
    void setAuthor(QString author){ this->author= author; }
    void setIsbn(QString isbn){ this->isbn= isbn; }
    void setCategory(int category_id){ this->category_id = category_id; }

    // Manage database table
    static bool createTable();
    static bool dropTable();
    static bool clearTable();

    // Crud
    bool save();
    bool update();
    bool destroy();

    // Get records from database
    static QVariantList getAll();
    static Book* getByIsbn(QString isbn);
};}}

#endif // BOOK_H
