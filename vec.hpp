#ifndef __VECTOR__hpp
#define __VECTOR__hpp

class Vec{
	private:
		int *array;
		int capacity;
		int count;

		void expandCapacity();

	public:
		Vec();
		~Vec();
		int getsize();
		bool empty();
		void set(int pos, int val);
		void push_back(int x);
		void pop_back();
		int get(int pos);
		int getfront();
		int getlast();
		void display();
};

#endif 

