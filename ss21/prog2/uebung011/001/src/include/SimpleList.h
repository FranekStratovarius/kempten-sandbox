#pragma once

#include <string>
#include <stdexcept>


using namespace std;

template <class T>
class SimpleList {

private:
	class ListNode {
	public:
		ListNode() {
			data = T();
			next = nullptr;
		}

		ListNode(const T data) {
			this->data = data;
			next = nullptr;
		}

		T data;
		ListNode* next;
	};

public:
	class SimpleListIterator {
		friend SimpleList;

	public:

		SimpleListIterator() {
			myElement = nullptr;
		}

		SimpleListIterator(ListNode* node) {
			myElement = node;
		}

		inline T& operator*() {
			return myElement->data;
		}

		inline T& operator->() {
			return myElement->data;
		}

		SimpleListIterator& operator++(int) {
			if (myElement != nullptr) {
				myElement = myElement->next;
			}
			return *this;
		}


		inline bool operator==(const SimpleListIterator& other) const {
			return other.myElement == myElement;
		}

		inline bool operator!=(const SimpleListIterator& other) const {
			return !(*this == other);
		}

	private:
		ListNode* myElement;
	};



public:
	SimpleList() {
		beforeBeginNode = ListNode();
		globalBeforeBeginIterator = SimpleListIterator(&beforeBeginNode);
		globalEndIterator = SimpleListIterator();
		listSize = 0;
	}

	~SimpleList() {
		clear();
	}

	inline unsigned int size() {
		return listSize;
	}

	void clear() {
		ListNode* node = beforeBeginNode.next;
		while (node != nullptr) {
			ListNode* p = node;
			node = node->next;
			delete p;
		}
		beforeBeginNode.next = nullptr;
		listSize = 0;
	}

	T& front() const {
		if (beforeBeginNode.next == nullptr)
			throw logic_error("Access to empty list");
		else
			return beforeBeginNode.next->data;
	}

	inline bool empty() const {
		return (beforeBeginNode.next == nullptr);
	}

	void push_front(const T& value) {
		ListNode* newFront = new ListNode(value);
		newFront->next = beforeBeginNode.next;
		beforeBeginNode.next = newFront;
		listSize++;
	}

	void pop_front() {
		if (beforeBeginNode.next != nullptr) {
			ListNode* oldFront = beforeBeginNode.next;
			beforeBeginNode.next = beforeBeginNode.next->next;
			delete oldFront;
			listSize--;
		}
	}

	inline SimpleListIterator before_begin() {
		return globalBeforeBeginIterator;
	}

	inline SimpleListIterator begin() {
		return SimpleListIterator(beforeBeginNode.next);
	}

	inline SimpleListIterator end() {
		return SimpleListIterator();
	}

	SimpleListIterator insert_after(const SimpleListIterator& iter, const T& value) {
		if (iter != nullptr && iter != globalEndIterator) {
			ListNode* newNode = new ListNode(value);
			newNode->next = iter.myElement->next;
			iter.myElement->next = newNode;
			listSize++;
			return SimpleListIterator(newNode);
		}
		return globalEndIterator;
	}



private:
	ListNode beforeBeginNode;
	unsigned int listSize;
	SimpleListIterator globalEndIterator;
	SimpleListIterator globalBeforeBeginIterator;
};


template <class T>
string to_string(SimpleList<T>& li) {
	string s = "(list: ";
	unsigned int i = 0;
	for (auto iter = li.begin(); iter != li.end(); iter++) {
		T value = *iter;
		s = s + to_string(value);
		if (i < li.size() - 1) 
			s = s + ", ";
		i++;
	}
	s = s + ")";
	return s;
}




