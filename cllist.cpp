#include "cllist.h"
using namespace std;
#include <string.h>
#include "clparser.h"

void ClList::createItem(std::string line){
    ClParser *temp = new ClParser;
    temp->read_txt(line);
    temp->setNext(NULL);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->setNext(temp);
        tail=temp;
    }
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
