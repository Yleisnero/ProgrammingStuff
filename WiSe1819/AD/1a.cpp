#include <iostream>

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
    element* getFirstElement();
    void quicksort();
    element* quicksortRec(element *h, element *end);
    element* partition(element *h, element *end, element **newHead, element **newEnd);
};

element* getTail(element*);

int main() {
    list myList;
    myList.append(5);
    myList.append(2);
    myList.append(3);
    myList.append(8);
    myList.append(453);
    myList.append(-2);
    myList.print();
    myList.quicksort();
    myList.print();
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
        if(first->next != nullptr){
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

    while(curr != nullptr){
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
    elem->next = nullptr;
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
    while(curr != nullptr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int list::length() {
    element *curr = head;
    int l = 0;
    while(curr != nullptr){
        l++;
        curr = curr->next;
    }
    return l;
}

element* list::getFirstElement(){
    return head;
}

element* getTail(element *cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

void list::quicksort(){
    (head) = quicksortRec(head, getTail(head));
}

element* list::quicksortRec(element *h, element *end){

    if(!h || h == end){
        return h;
    }

    element *newHead = nullptr;
    element *newEnd = nullptr;

    element *pivot = partition(h, end, &newHead, &newEnd);

    if(newHead != pivot){

        element *curr = newHead;
        while(curr->next != pivot){
            curr = curr->next;
        }
        curr->next = nullptr;
        newHead = quicksortRec(newHead, curr);

        curr = getTail(newHead);
        curr->next = pivot;
    }

    pivot->next = quicksortRec(pivot->next, newEnd);
    return newHead;
}

element* list::partition(element *h, element *end, element **newHead, element **newEnd){
    element *pivot = end;
    element *prev = nullptr;
    element *curr = h;
    element *tail = pivot;

    while(curr != pivot) {
        if (curr->val < pivot->val) {
            if ((*newHead) == nullptr) {
                (*newHead) = curr;
            }

            prev = curr;
            curr = curr->next;
        } else {
            if (prev) {
                prev->next = curr->next;
            }
            element *tmp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }

    if((*newHead) == nullptr){
        (*newHead) = pivot;
    }

    (*newEnd) = tail;

    return pivot;
}