#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
	this->head = NULL;
	this->tail = NULL;
	this->listSize = 0;
}

Map::~Map() {
	//TODO - Implementation
	Node* currentNode = this->head;
	Node* nextNode = this->head;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	delete nextNode;
}

/*
The adding will have 2 scenarios :
	- If the key exists : update the value - Complexity O(n), because of searching the pair with the key
	- If the key does not exist : add it along with the value - Complexity O(1)


	
	- Total Complexity - Theta(n) 
	- n - number of nodes in the list
*/
TValue Map::add(TKey c, TValue v){
	//TODO - Implementation
	Node* currentNode = this->head;
	while (currentNode != NULL && currentNode->info.first != c)
		currentNode = currentNode->next;
	if(currentNode != NULL)
	{
		int oldValue = currentNode->info.second;
		currentNode->info.second = v;
		return oldValue;

	} // iterated list, not found
	else
	{
		Node* addNode = new Node();
		addNode->info.first = c;
		addNode->info.second = v;
		addNode->next = NULL;
		addNode->prev = this->tail;
		if (this->head == NULL)
		{
			this->head = addNode;
			this->tail = addNode;
		}
		else
		{
			this->tail->next = addNode;
			this->tail = addNode;
		}
		this->listSize++;
		return NULL_TVALUE;
	}

	
}

/*
Complexity - O(n)
n - number of nodes
*/
TValue Map::search(TKey c) const{
	Node* currentNode = this->head;
	while (currentNode != NULL && currentNode->info.first != c)
		currentNode = currentNode->next;
	if (currentNode == NULL)
		return NULL_TVALUE;
	return currentNode->info.first;
	

}
// Complexity - O(n)
TValue Map::remove(TKey c){
	//TODO - Implementation
	Node* currentNode = this->head;
	while (currentNode != NULL && currentNode->info.first != c)
		currentNode = currentNode->next;
	Node* deletedNode = currentNode;
	if (currentNode != NULL)
	{
		if (currentNode == this->head)
			if (currentNode == this->tail)
			{
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				this->head = this->head->next;
				this->head->prev = NULL;
			}
		else if (currentNode == this->tail)
		{
			this->tail = this->tail->prev;
			this->tail->next = NULL;
		}
		else
		{
			currentNode->next->prev = currentNode->prev;
			currentNode->prev->next = currentNode->next;
		}
		this->listSize--;
		return deletedNode->info.second;
	}
	
	return NULL_TVALUE;
}

// Complexity - Theta(1)
int Map::size() const {
	//TODO - Implementation
	return this->listSize;
}

// Complexity - Theta(1)
bool Map::isEmpty() const{
	//TODO - Implementation
	return this->listSize == 0;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



