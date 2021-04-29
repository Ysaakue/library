#include "category.h"

using namespace library::models;

/**
 * @brief Init the database and set default values to class attributes
 */
Category::Category(){
    Category::_init();
    this->id = 0;
}

/**
 * @brief Init the database and set the attributes from params
 * @param description The Category's description
 */
Category::Category(QString description){
    Category::_init();
    this->id = 0;
    this->description = description;
}

/**
 * @brief Init the database and set the attributes from params
 * @param id The Category's identifier
 * @param description The Category's description
 */
Category::Category(int id, QString description){
    Category::_init();
    this->id = id;
    this->description = description;
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
                            description TEXT not null unique);";

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

/**
 * @brief Get all records from database
 * @return Categories as QVariantMap
 */
QVariantList Category::getAll(){
    Category::_init();
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return QVariantList();
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "select * from categories;";

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

    QVariantList categories;
    while(query.next()){
        QVariantMap categoryMap;
        categoryMap.insert("id", query.value(0).toInt());
        categoryMap.insert("description", query.value(1).toString());

        categories.append(categoryMap);
    }
    Database::database.close();

    return categories;
}

/**
 * @brief Get all category's descriptions from database
 * @return The descriptions as QString
 */
QStringList Category::getAllDescriptions(){
    Category::_init();
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return QStringList();
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "select description from categories;";

    if(Database::database.isValid() && Database::database.isOpen()){
        if (!query.prepare(sqlStatement)){
            Database::database.close();
            qDebug() << "ERROR: Query not prepared";
            return QStringList();
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (preparation)";
        return QStringList();
    }

    if(Database::database.isValid() && Database::database.isOpen()){
        if(!query.exec()){
            qDebug() << query.lastError().text();
            Database::database.close();
            return QStringList();
        }
    } else {
        qDebug() << "ERROR: Invalid or closed (execution)";
        return QStringList();
    }

    QStringList categories;
    while(query.next()){
        categories.append(query.value(0).toString());
    }
    Database::database.close();

    return categories;
}

/**
 * @brief Get a Category filtred by description
 * @param description The Categories's description
 * @return The Category filtred by description if was found and null if a error or the Category was not found
 */
Category* Category::getByDescription(QString description){
    Category::_init();
    if(!Database::database.open()) {
        qDebug() << "ERROR: trying to open the database";
        return NULL;
    }

    QSqlQuery query(Database::database);

    QString sqlStatement = "select * from categories where description = :description;";

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

    query.bindValue(":description", QVariant(description));

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

    int _id = 0;
    QString _description;
    while(query.next()){
        _id =query.value(0).toInt();
        _description = query.value(1).toString();
    }
    Database::database.close();

    if(_id<=0) return NULL;

    return new Category(_id,_description);
}
