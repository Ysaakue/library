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
    Q_INVOKABLE QStringList getAllCategoriesDescriptions();

    Q_INVOKABLE bool saveBook(QString isbn,QString name,QString author, QString category_description);
    Q_INVOKABLE bool updateBook(QString isbn,QString name,QString author, QString category_description);
    Q_INVOKABLE bool destroyBook(QString isbn);

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
