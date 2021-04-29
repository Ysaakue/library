#include "database_controller.h"
#include "models/category.h"
#include "models/book.h"

using namespace library::controllers;
using namespace library::models;

DatabaseController::DatabaseController(){}

/**
 * @brief Get the description from all categories from database
 * @return the descriptions as QString
 */
QStringList DatabaseController::getAllCategoriesDescriptions(){
    return Category::getAllDescriptions();
}

/**
 * @brief Get all categories from database
 * @return the categories as QVariantMap
 */
QVariantList DatabaseController::getAllCategories(){
    return Category::getAll();
}

/**
 * @brief Get all books from database
 * @return the books as QVariantMap
 */
QVariantList DatabaseController::getAllBooks(){
    return Book::getAll();
}

/**
 * @brief Create a book with the attributes received as params and emit the signal bookAdded if
 * book was saved
 * @param isbn Code that identifies  the book
 * @param name The books's name
 * @param author The book's author's name
 * @param category_description The Category's description
 * @return true if success and false if an error occurred
 */
bool DatabaseController::saveBook(QString isbn,QString name,QString author, QString category_description){
    if(!Book(isbn,name,author,Category::getByDescription(category_description)->getId()).save())
        return false;
    emit bookAdded();
    return true;
}

/**
 * @brief Update the Book find by isbn with the attributes received by params and emit the bookUpdated signal if book was updated
 * @param isbn Code that identifies  the book
 * @param name The books's name
 * @param author The book's author's name
 * @param category_description The Category's description
 * @return true if success and false if an error occurred
 */
bool DatabaseController::updateBook(QString isbn,QString name,QString author, QString category_description){
    Book* book = Book::getByIsbn(isbn);
    qDebug() << name;
    book->setName(name);
    book->setAuthor(author);
    book->setCategory(Category::getByDescription(category_description)->getId());
    if(!book->update())
        return false;
    emit bookUpdated(book->toVariantMap());
    return true;
}

/**
 * @brief Get the book by isbn received as params and emit the signal bookDeleted if the book was deleted
 * @param isbn The isbn of book to delete
 * @return true if success and false if an error occurred
 */
bool DatabaseController::destroyBook(QString isbn){
    if(!Book::getByIsbn(isbn)->destroy())
        return false;
    emit bookDeleted();
    return true;
}
