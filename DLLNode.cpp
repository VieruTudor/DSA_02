#include "DLLNode.h"
#pragma once

Node::Node(Node* prev, TElem info, Node* next)
{
	this->prev = prev;
	this->info = info;
	this->next = next;
}

TElem Node::getElement()
{
	return this->info;
}

void Node::setElement(TElem element)
{
	this->info = element;
}

Node* Node::getPrev()
{
	return this->prev;
}

Node* Node::getNext()
{
	return this->next;
}
