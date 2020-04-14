#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	first();
}

// Complexity - Theta(1)
void MapIterator::first() {
	//TODO - Implementation
	if (map.listSize > 0)
		currentNode = map.head;
	else
	{
		currentNode = NULL;
	}
}

// Complexity - Theta(1)
void MapIterator::next() {
	//TODO - Implementation
	if (!valid())
		throw exception();
	currentNode = currentNode->next;
}

// Complexity - Theta(1)
void MapIterator::previous()
{
	if (!valid())
		throw exception();
	currentNode = currentNode->prev;
}


// Complexity - Theta(1)
void MapIterator::setCurrentNode(Node* setNode)
{
	currentNode = setNode;
}


// Complexity - Theta(1)
Node* MapIterator::getCurrentNode()
{
	return this->currentNode;
}

// Complexity - Theta(1)
TElem MapIterator::getCurrent(){
	//TODO - Implementation
	if (currentNode == NULL)
		throw exception();
	return this->currentNode->info;
}

// Complexity - Theta(1)
bool MapIterator::valid() const {
	//TODO - Implementation
	if (currentNode != NULL)
		return true;
	return false;
}



