#pragma once

#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class Node {
private:
	Node* prev;
	Node* next;
	TElem info;
public:
	Node(Node* prev, TElem info, Node* next);
	TElem getElement();
	void setElement(TElem element);
	Node* getPrev();
	Node* getNext();
};

