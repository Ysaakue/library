#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace library{
namespace models {
class Database {
protected:
    Database();
    static QSqlDatabase database;
    static bool initiated;
    static void _init();
};}}

#endif // DATABASE_H
