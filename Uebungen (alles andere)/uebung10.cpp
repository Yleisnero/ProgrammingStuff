#include <iostream>
using namespace std;

class student{
	private:
		string name;
		unsigned int grade{};
		mutable int vergleiche;
        static int anzahl;
	public:
        bool operator < (const student &s) const{
            vergleiche++;
            //cout << vergleiche << endl; only for debugging & not working -> stupid cunt
            return this->getGrade() < s.getGrade();
        };
		student() = default; //needed for overcoming memory weirdness
		student(string name, unsigned int grade) : name(std::move(name)), grade(grade) {anzahl++;}
		~student(){anzahl--;}
		int getGrade()const { return grade; }
		string getName() const { return name; }
};

int student::anzahl = 0;

template <typename element> //template class declaration
class list {
	private:
	element data; list *head, *next;
	public:
	list(){head = nullptr;
		next = nullptr;} //needed for allocating pointer memory

	element getData(int ind){

        list *tmp = head;
        for (int i = 0; i < ind; i++){
            tmp = tmp->next;
        }

        return tmp->data;
	}
	void add(element &e){
        list *newEntry;
		if(head == nullptr){
			head = new list();
			head->data = e;
			head->next = nullptr;
		}else {
			newEntry = head;
			while(newEntry->next != nullptr){
				newEntry = newEntry->next;
			}
            newEntry->next = new list();
			newEntry = newEntry->next;
			newEntry->data = e;
			newEntry->next = nullptr;
		}
	}
	int size(){
	    list *tmp = head;
	    int res = 0;
	    while (tmp != nullptr){
	        res++;
	        tmp = tmp->next;
	    }
	    return res;
	}

	int getBest(){
	    int best = 0;
        for (int i = 0; i < size()-1; i++){ //own for each
            if(getData(i) < getData(i+1) && getData(i) < getData(best)) {
                best = i;
            } else if (getData(i+1) < getData(i) && getData(i+1) < getData(best)) {
                best = i + 1;
            }
        }
        return best;
	}
};

//template <typename T> T getMax(T a, T b){ return a > b ? a : b;} example template

int main(){
	student eumel("Jonas", 5);
	student hallo("Korbi", 1);
	student test("Test", 6);
	student meixi("Meixner", 4);
	student zindy("Cindy", 0);
	student loool("Dope", 3);
        list<student> studentList;
	studentList.add(eumel);
	studentList.add(hallo);
	studentList.add(test);
	studentList.add(meixi);
	studentList.add(zindy);
	studentList.add(loool);
	cout << studentList.getData(studentList.getBest()).getName() << " ist das kluegste Student!" << endl;
	return 0;
}
