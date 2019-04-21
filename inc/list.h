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
	void push_back(const T&);
	void pop_back();
	void write() const;
	
	bool empty() const {return head_ == nullptr;}
	int size() const {return size_;}

private:
	int size_;
	ListItem<T>* head_;
	ListItem<T>* tail_;
};

#endif