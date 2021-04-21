#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

class Category {
private:
    int id;
    QString description;

public:
    Category();

    // Getters
    int getId(){ return this->id; }
    QString getDescription(){ return this->description; }

    // Setters
    void setId(int id){ this->id = id; }
    void setDescription(QString description){ this->description = description; }
};

#endif // CATEGORY_H
