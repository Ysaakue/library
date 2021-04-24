#include "category.h"

using namespace library::models;

Category::Category(){
    Category::_init();
    this->id = 0;
}

/**
 * @brief Create database table
 * @return true if success and false if an error occurred
 */
bool Category::createTable(){
    Category::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "create table if not exists categories(id INTEGER constraint categories_pk primary key autoincrement, \
                            description TEXT not null);";

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
bool Category::dropTable(){
    Category::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "drop table if exists categories;";

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
bool Category::clearTable(){
    Category::_init();
    if(!Database::database.open()){
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "delete from categories;";

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
 * @brief Save the Category in database
 * @return true if success and false if an error occurred
 */
bool Category::save(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "insert into categories (description) values (:description);";

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

    query.bindValue(":description", QVariant(this->description));

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

    this->setId(query.lastInsertId().toInt());

    if(query.numRowsAffected() > 0){
        Database::database.close();
        return true;
    } else {
        Database::database.close();
        return false;
    }
};

/**
 * @brief Update Category's data on database
 * @return true if success and false if an error occurred
 */
bool Category::update(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "update categories set description=:description where id=:id;";

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

    query.bindValue(":description", QVariant(this->description));
    query.bindValue(":id", QVariant(this->id));

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
 * @brief Delete the Category from database
 * @return true if success and false if an error occurred
 */
bool Category::destroy(){
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return false;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "delete from categories where id=:id;";

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

    query.bindValue(":id", QVariant(this->id));

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
