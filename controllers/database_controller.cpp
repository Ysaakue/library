#include "database_controller.h"
#include "models/category.h"
#include "models/book.h"

using namespace library::controllers;
using namespace library::models;

DatabaseController::DatabaseController()
{

}


QVariantList DatabaseController::getAllCategories(){
    return Category::getAll();
}

QVariantList DatabaseController::getAllBooks(){
    return Book::getAll();
}
