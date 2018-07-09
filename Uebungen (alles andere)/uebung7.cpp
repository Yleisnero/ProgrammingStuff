#include "std_lib_facilities.h"

template <typename T>
T getMax(const T el1, const T el2){
	if(el1 > el2){
		return el1;	
	}else{
		return el2;
	}
}

template <typename T>
struct node {T data; node *next;};

struct student{string name; int note;};

int operator > (const student &st1, const student &st2){
  cout<< st2.note - st1.note << "'''''''''''''\n";
	return st1.note > st2.note;
}

template<typename T>
class linkedList{
	public:
	linkedList(){
		head = new node<T>;
		tail = new node<T>;
		head->next = tail->next = tail;
	}

	void insertAfter(T data, node<T> *n)  {
    		node<T> *x = new node<T>;
		x->data = data;  
    		x->next = n->next;
		n->next = x;
	}

	void deleteNext(node<T> *n)  {
    		node<T> *toDel = n->next; 
   		n->next = n->next->next; 
		delete toDel; 
	}

	node<T> *getHead(){return head;}

	node<T> *getTail(){return tail;}
	
	private:
	node<T> *head, *tail;
};

int main(){

	linkedList<int> myList;
	myList.insertAfter(4, myList.getHead());

	student jonas;
	jonas.name = "jonasF";
	jonas.note = 1;

	student mona;
	mona.name = "mona";
	mona.note = 6;

	linkedList<student> stuList;
	stuList.insertAfter(jonas, stuList.getHead());

	

	student max = getMax<student>(jonas, mona);
	cout << "Max: " << max.name << endl;
	
}
