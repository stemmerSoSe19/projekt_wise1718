#ifndef CLLIST_H
#define CLLIST_H
#include "clparser.h"
#include <string>

class ClList
{
    public:
        ClList() { head=NULL; tail=NULL; }
        int createItem(std::string line, std::string xml);
        void printAll();
        void printSearch(int log_op, int arg1, int arg2, std::string query1, std::string query2);

    private:
        ClParser *head, *tail;

};

#endif // CLLIST_H
