#include "book.h"

using namespace library::models;

Book::Book(){
    Book::_init();
    this->isbn = "";
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
