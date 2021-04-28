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
bool DatabaseController::saveBook(QString isnb,QString name,QString author, QString category_description){
    if(!Book(isnb,name,author,Category::getByDescription(category_description)->getId()).save())
        return false;
    emit bookAdded();
    return true;
}
