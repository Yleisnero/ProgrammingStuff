#include "std_lib_facilities.h"
namespace linkedList {  using element = int;
  struct node { element data; node *next; }  *head, *z;
  void init( ) { head = new node;
               z = new node;
               head->next = z->next = z; } // more listOps ... */ 
  void insertAfter(element data, node *n)  {
    node *x = new node;  x->data = data;  
    x->next = n->next; n->next = x; }
  void deleteNext(node *n)  {
    node *toDel = n->next; 
    n->next = n->next->next;  delete toDel;  } 
} 
int main( )  {
  using namespace linkedList;
  init( ); int input;
  cout << "enter some numbers (end your input with 'q')" << endl;
  node *current = head;
  while (cin >> input)  
    insertAfter(input, current), current = current->next;
  cout << "your input was: ";  current = head->next;
  node *node::*np = &node::next; 
  while (current != current->*np /* alternativ: *current.*np */) 
    cout << current->data << " ", current = current->next; 
  while (head->next != z)  deleteNext(head); 
  cout << endl;  return 0;  } 
