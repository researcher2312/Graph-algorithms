#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
	List();
	~List();
	void add(T*);
	void write();
private:
	struct {
		T* head;
		T* tail;
	}info;




	
};

#endif