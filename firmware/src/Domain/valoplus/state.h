#ifndef TEST_STATE_H
#define TEST_STATE_H


class State  {
	private:
		
	public:
		virtual bool getActive()= 0;
		virtual void setActive(bool active)= 0;
};

#endif //TEST_STATE_H
