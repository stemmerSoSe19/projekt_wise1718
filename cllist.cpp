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

void ClList::displayAll(){
    ClParser *temp= new ClParser;
    temp=head;
    while(temp!=NULL)
    {
      temp->print();
      temp=temp->getNext();
    }
}

//TODO
//void ClList::displaySearch(std::string arg1, std::string arg2, std::string query1, std::string query2){
//    ClParser *temp= new ClParser;
//    temp=head;
//    while(temp!=NULL)
//    {
//        temp->print();
//        temp=temp->getNext();
//    }
//}
