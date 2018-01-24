#ifndef CLLIST_H
#define CLLIST_H
#include "clparser.h"
#include <string>

class ClList
{
    public:
        ClList() { head=NULL; tail=NULL; }
        int createItem(std::string line, std::string xml);
        void displayAll();
        void displaySearch(std::string arg1, std::string arg2, std::string query1, std::string query2);

    private:
        ClParser *head, *tail;

};

#endif // CLLIST_H
