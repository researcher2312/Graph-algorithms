#include "list.h"

#include "graph_elements.h"

#include <iostream>

using namespace std;

template <typename T>
List<T>::List() {
	head_ = tail_ = nullptr;
	size_ = 0;
}

template <typename T>
void List<T>::push_back(const T& value) {
	ListItem<T>* q = new ListItem<T>;
	q -> item = value;
	q -> next = nullptr;
	if (empty()) {
		head_ = tail_ = q;
	}
	else {
		tail_->next = q;
		tail_ = q;
	}
	size_++;
}

template <typename T>
void List<T>::write() const {
	ListItem<T>* q = head_;
	if (empty()) {
		cout << "list is empty";
	}
	while (q != nullptr) {
		cout << q->item << ' ';
		q = q->next;
	}
	cout << '\n';
}

template <typename T>
bool List<T>::contains(T searched_item){
	ListItem<T>* searched = head_;
	while (searched != nullptr){
		if (searched->item == searched_item)
			return 1;
		searched = searched->next;
	}
	return 0;
}

template <typename T>
ListItem<T> List<T>::front(){
	ListItem<T> &head = *head_;
	return head;
}

template <typename T>
ListItem<T> List<T>::back(){
	ListItem<T> &tail = *tail_;
	return tail;
}

template class List<int>;
template class List<GraphVertice*>;
template class List<GraphEdge*>;
