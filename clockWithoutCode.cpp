#include "std_lib_facilities.h"
#include <chrono>
#include <thread>
#include <cassert>
#include <vector>

#define validTime(h, m, s) assert(h >= 0 && h < 24), assert(m >= 0 && m < 60), \
						assert(s >= 0 && s < 60)


class Clock{

	public:
	unsigned h, m, s;

	Clock(unsigned h, unsigned m, unsigned s) : h(h), m(m), s(s){
		validTime(h, m, s);
 	}

	virtual void tick(){
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};

class alarmClock : public Clock{

	using Clock::Clock; //Konstruktor aus class Clock
	
	thread *ringtone;
	long remainingSeconds;

	public:
	void sleep(){
		ringtone->join(); //waiting for thread ringtone
	}

	void setAlarm(unsigned h, unsigned m, unsigned s){
		validTime(h, m, s);
		long now = ((this->h * 60 + this->m) * 60 + this->s);
		long then = ((h * 60 + m) * 60 + s);
		remainingSeconds = now < then ? then - now : 24 * 60 * 60 - now + then;
		
		 });
	}

};

int main(){

	vector<Clock *> clocks {
		new Clock{ 11, 0 , 0},
		new alarmClock{11, 0, 0}
	};

	Clock *c = nullptr;
	bool found = false;
	int i = 0;

	while(!found){
		
	}

	if(c != nullptr){
		
	}

return 0;
}
