#include "database.h"
#include "book.h"
#include "category.h"

using namespace library::models;

bool Database::initiated = false;
QSqlDatabase Database::database = QSqlDatabase::addDatabase("QSQLITE");

Database::Database(){
    _init();
}

/**
 * @brief Set database file path and create the tables
 */
void Database::_init(){
   database.setDatabaseName("/tmp/library.sqlite");

   Book::createTable();
   Category::createTable();
}
