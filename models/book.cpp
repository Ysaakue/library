#include "book.h"

using namespace library::models;

/**
 * @brief Init the database and set default values to class attributes
 */
Book::Book(){
    Book::_init();
    this->isbn = "";
}

/**
 * @brief Init the database and set the attributes from params
 * @param isbn Code that identifies  the book
 * @param name The books's name
 * @param author The book's author's name
 * @param category_id The category's id
 */
Book::Book(QString isbn, QString name, QString author, int category_id){
    Book::_init();
    this->isbn = isbn;
    this->name = name;
    this->author = author;
    this->category_id = category_id;
}

/**
 * @brief Create database table
 * @return true if success and false if an error occurred
 */
bool Book::createTable(){
    Book::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "create table if not exists books(isbn TEXT constraint categories_pk primary key, \
                            name TEXT, author TEXT, category_id INTEGER references categories);";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    if (!query.exec()){
        qDebug() << "ERROR:" << query.lastError().text();
        Database::database.close();
        return false;
    }

    Database::database.close();
    return true;
}

/**
 * @brief Drop database table
 * @return true if success and false if an error occurred
 */
bool Book::dropTable(){
    Book::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "drop table if exists books;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    if (!query.exec()){
        qDebug() << "ERROR:" << query.lastError().text();
        Database::database.close();
        return false;
    }

    Database::database.close();
    return true;
}

/**
 * @brief Clear database table
 * @return true if success and false if an error occurred
 */
bool Book::clearTable(){
    Book::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "delete from books;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    if (!query.exec()){
        qDebug() << "ERROR:" << query.lastError().text();
        Database::database.close();
        return false;
    }

    Database::database.close();
    return true;
}

/**
 * @brief Save the Book in database
 * @return true if success and false if an error occurred
 */
bool Book::save(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "insert into books (isbn,name,author,category_id) values (:isbn,:name,:author,:category_id);";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    query.bindValue(":isbn", QVariant(this->isbn));
    query.bindValue(":name", QVariant(this->name));
    query.bindValue(":author", QVariant(this->author));
    query.bindValue(":category_id", QVariant(this->category_id));

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return false;
    }

    if(query.numRowsAffected() > 0){
        Database::database.close();
        return true;
    } else {
        Database::database.close();
        return false;
    }
};

/**
 * @brief Update Book's data on database
 * @return true if success and false if an error occurred
 */
bool Book::update(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "update books set isbn=:isbn, name=:name, author=:author, category_id=:category_id where id=:id;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    query.bindValue(":isbn", QVariant(this->isbn));
    query.bindValue(":name", QVariant(this->name));
    query.bindValue(":author", QVariant(this->author));
    query.bindValue(":category_id", QVariant(this->category_id));

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return false;
    }

    if(query.numRowsAffected() > 0){
        Database::database.close();
        return true;
    } else {
        Database::database.close();
        return false;
    }
};

/**
 * @brief Delete the Book from database
 * @return true if success and false if an error occurred
 */
bool Book::destroy(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "delete from books where isbn=:isbn;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return false;
    }

    query.bindValue(":isbn", QVariant(this->isbn));

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return false;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return false;
    }

    if(query.numRowsAffected() > 0){
        Database::database.close();
        return true;
    } else {
        Database::database.close();
        return false;
    }
};

/**
 * @brief Get all records from database
 * @return Books as QVariantMap
 */
QVariantList Book::getAll(){
    Book::_init();
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return QVariantList();
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "select * from books;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return QVariantList();
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return QVariantList();
    }

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return QVariantList();
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return QVariantList();
    }

    QVariantList books;
    while(query.next()){
        QVariantMap bookMap;
        bookMap.insert("isbn", query.value(0).toString());
        bookMap.insert("name", query.value(1).toString());
        bookMap.insert("author", query.value(2).toString());
        bookMap.insert("category_id", query.value(4).toInt());

        books.append(bookMap);
    }
    Database::database.close();

    return books;
}

/**
 * @brief Get a Book filtred by isbn
 * @param isbn The Book's isbn
 * @return The Book filtred by isbn if was found and null if a error or the Book was not found
 */
Book* Book::getByIsbn(QString isbn){
    Book::_init();
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return NULL;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "select * from books where isbn = :isbn;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return NULL;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return NULL;
    }

    query.bindValue(":isbn", QVariant(isbn));

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return NULL;
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return NULL;
    }

    QString _isbn;
    QString _name;
    QString _author;
    int _category = 0;
    while(query.next()){
        _isbn = query.value(0).toString();
        _name = query.value(1).toString();
        _author = query.value(2).toString();
        _category = query.value(3).toInt();
    }
    Database::database.close();

    if(_isbn == "")return NULL;

    return new Book(_isbn,_name,_author,_category);
}
