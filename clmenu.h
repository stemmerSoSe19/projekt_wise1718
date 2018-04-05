#ifndef CLMENU_H
#define CLMENU_H
#include "cllist.h"

class ClMenu{
    public:
        ClMenu();
        void init();
        int splash();
        int subMenu();
        void search();
        void searchMenu();

    private:
        ClList *list;
};

#endif // CLMENU_H
