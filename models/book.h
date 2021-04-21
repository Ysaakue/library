#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
private:
    int id;
    QString name;
    QString author;
    QString isbn;
    int category_id;

public:
    Book();

    // Getters
    int getId(){ return this->id; }
    QString getName(){ return this->name; }
    QString getAuthor(){ return this->author; }
    QString getIsbn(){ return this->isbn; }

    // Setter
    void setId(int id){ this->id = id; }
    void setName(QString name){ this->name = name; }
    void setAuthor(QString author){ this->author= author; }
    void setIsbn(QString isbn){ this->isbn= isbn; }
};

#endif // BOOK_H
