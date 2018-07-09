#include <cstdlib>
namespace linkedList {
	using element = int;

	struct node {
		element data; node *next;
	} *head, *z;

void init( ) {
	head = new node;
	z = new node;
	head->next = z->next = z; } /* more listOps ... */ }

void insert(int data){
	if(head->next == z){
		node newNode = new node(data, head->next);
		head->next = newNode;
	}
}

int main( ) {
	using namespace linkedList;
	init( ); // use linkedList ...
	insert()
	return 0;
}
