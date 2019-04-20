#ifndef LIST_H
#define LIST_H

template <typename T>
struct ListItem {
	T item;
	ListItem* next;
};

template <typename T>
class List {
public:
	List();
	~List();
	void add(T*);
	void write();

	bool empty(){return head == nullptr;}

private:
	T* head;
	T* tail;
	




	
};

#endif