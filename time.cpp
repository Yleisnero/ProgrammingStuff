#include <iostream>
#include <time.h>
using namespace std;

class Time {

	public:
	Time( ){}
	Time(int h, int m = 0, int s = 0) : hour(h), min(m), sec(s){}

	int getH(){return hour;}
	int getM(){return min;}
	int getS(){return sec;}
	
	void setTime(int h, int m, int s){
		hour = h;
		min = m;
		sec = s;
	}

	Time operator +(unsigned int plus){
		int hTmp = hour + ((plus / 60) / 60);
		int mTmp = min + ((plus / 60) % 60);
		int sTmp = sec + (plus % 60);
		if(hTmp >= 24){
			hTmp = hTmp - 24;
		}
		if(mTmp >= 60){
			mTmp = mTmp - 60;
			hTmp++;
		}
		if(sTmp >= 60){
			sTmp = sTmp - 60;
			min++;
		}
		Time tTmp(hTmp, mTmp, sTmp);
		
		return tTmp;
	}
	
	Time &operator +=(unsigned int plus){
		hour = hour + ((plus / 60) / 60);
		min = min + ((plus / 60) % 60);
		sec = sec + (plus % 60);
		if(hour >= 24){
			hour = hour - 24;
		}
		if(min >= 60){
			min = min - 60;
			hour++;
		}
		if(sec >= 60){
			sec = sec - 60;
			min++;
		}
		
		return *this;
	}
	
	int operator ()(){
		time_t timer;
		time(&timer);
		int mySec = 60*60*hour + 60*min + sec;
		return timer - mySec;
	}

	Time operator ,(Time &t){
		Time tmp((hour + t.getH()) / 2, (min + t.getM()) / 2, (sec + t.getS()) / 2);
		return tmp;
	}

	Time &operator ++( );
	// prefix version
	Time operator ++(int); // postfix version
	Time operator -(unsigned int) const;
	Time &operator -=(unsigned int);
	Time &operator --( );
	// prefix version
	Time operator --(int); // postfix version
	bool operator ==(const Time &) const;
	bool operator <(const Time &) const;
	bool operator >(const Time &) const;

	private:
	int hour, min, sec;
	friend ostream &operator <<(ostream &, const Time &);
	friend bool operator <=(const Time &, const Time &);
	friend bool operator >=(const Time &, const Time &);
	friend bool operator !=(const Time &, const Time &);
	friend unsigned int operator -(const Time &, const Time &);
};

ostream &operator << (ostream &outStream, Time &t){
	outStream << t.getH() << "h " << t.getM() << "min " << t.getS() << "sec " << endl;
	return outStream;
}

int main(){

	Time time(23, 59, 5);
	cout << time;
	time += 3661;
	cout << time;
	time = time + 3661;
	cout << time;
	cout << time() << endl;
	Time time2(1, 1, 1);
	Time time3(3, 3, 3);
	cout << time2,time3;

return 0;
}
