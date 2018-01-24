#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "clparser.h"
#include "cllist.h"

int main(){
    ClList *list;
    list = new ClList;
    ifstream input;
    string line;
    input.open("myList.txt");


    while (getline(input, line)){
        list->createItem(line);
    }

    list->displayAll();
    input.close();
}
