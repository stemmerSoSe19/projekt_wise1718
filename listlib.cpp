#include "cllist.h"
using namespace std;
#include <string.h>
#include "clparser.h"

int ClList::createItem(std::string line, std::string xml){
    ClParser *temp = new ClParser;
    //Fill item
    //Stops creation for this node if read_txt() returns error state 0
    if (temp->read_txt(line) == 0) return 0;
    temp->read_xml(xml);
    //Create list
    temp->setNext(NULL);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->setNext(temp);
        tail=temp;
    }
    return 1;
}

//Prints all entries in list
void ClList::printAll(){
    ClParser *temp= new ClParser;
    temp=head;
    while(temp!=NULL){
      temp->print();
      temp=temp->getNext();
    }
}

//Searches through list and prints entries that match search parameters
//log_op 0 = AND, log_op 1 = OR
//arg1 / arg2
// 0 = brand, 1 = type, 2 = iso, 3 = iso_used, 4 = color, 5 = format, 6 = date
void ClList::printSearch(int log_op, int arg1, int arg2, std::string query1, std::string query2){
    ClParser *temp= new ClParser;
    temp=head;
    while(temp!=NULL){
        switch(log_op){
            case 0:
                if(temp->search(arg1, query1) == 1 && temp->search(arg2, query2)) temp->print();
                break;
            case 1:
                if(temp->search(arg1, query1) == 1 || temp->search(arg2, query2)) temp->print();
                break;
        }
        temp=temp->getNext();
    }
}