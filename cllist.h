#ifndef CLLIST_H
#define CLLIST_H
#include "clparser.h"
#include <string>

class ClList
{
    public:
        ClList() { head=NULL; tail=NULL; }
        void displayAll();
        void createItem(std::string line);

    private:
        ClParser *head, *tail;

};

#endif // CLLIST_H
