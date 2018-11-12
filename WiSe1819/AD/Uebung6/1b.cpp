#include <iostream>
#include <random>
#include <time.h>

typedef int object;

class element{
public:
    object val;
    element *next;
};

class list{
private:
    element *head;
    element *tail;
    void deleteList(element *first);

public:
    list();
    ~list();
    void append(object o);
    void deleteList();
    void deleteValue(object o);
    void print();
    int length();
    object getValue(int pos);
};

int main() {
    list myList;
    for(int i = 1; i <= 49; i++){
        myList.append(i);
    }

    srand(time(NULL));

    int zahlen[6];
    for(int i = 0; i < 6; i++){
        int randInt = rand() % 49 + 1;
        zahlen[i] = myList.getValue(randInt);
        myList.deleteValue(zahlen[i]);
    }

    for(int i = 0; i < 6; i++){
        std::cout << zahlen[i] << " ";
    }
    return 0;
}

list::list(){
    head = nullptr;
    tail = nullptr;
}

list::~list() {
    deleteList(head);
    head = nullptr;
    tail = nullptr;
}

void list::deleteList(element *first) {
    if(first != nullptr){
        if(first->next != head){
            deleteList(first->next);
        }
    }
    delete first;
}

void list::deleteList() {
    deleteList(head);
}

void list::deleteValue(object o) {
    element *curr = head;
    element *prev = nullptr;

    while(curr->next != head){
        if(curr->val == o){
            if(prev == nullptr){
                head = curr->next;
            }else{
                prev->next = curr->next;
            }

            if(curr == tail){
                tail = prev;
            }

            element *h = curr;
            curr = curr->next;
            delete h;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void list::append(object o) {
    element *elem = new element;
    elem->val = o;
    elem->next = head;
    if(tail == nullptr){
        head = elem;
        tail = elem;
    }else{
        tail->next = elem;
        tail = elem;
    }
}

void list::print(){
    element *curr = head;
    while(curr->next != head){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int list::length() {
    element *curr = head;
    int l = 0;
    while(curr->next != head){
        l++;
        curr = curr->next;
    }
    return l;
}

object list::getValue(int pos) {
    element *curr = head;
    int l = 1;
    while(l <= pos){
        l++;
        curr = curr->next;
    }
    return curr->val;
}