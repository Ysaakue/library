#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include <QVariantMap>

namespace library{
namespace controllers {
class DatabaseController : public QObject{
    Q_OBJECT
public:
    DatabaseController();
    Q_INVOKABLE QVariantList getAllCategories();

    Q_INVOKABLE QVariantList getAllBooks();

signals:
    void categoryUpdated(QVariantMap);
    void categoryQAdded();
    void categoryDeleted();
    void bookUpdated(QVariantMap);
    void bookAdded();
    void bookDeleted();
};}}

#endif // DATABASECONTROLLER_H