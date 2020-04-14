#include "ShortTest.h"
#include <assert.h>
#include "Map.h"
#include "MapIterator.h"
#include <iostream>

void testAll() { //call each function to see if it is implemented
	Map m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==NULL_TVALUE);
	assert(m.add(1,111)==NULL_TVALUE);
	assert(m.add(10,110)==NULL_TVALUE);
	assert(m.add(7,7)==NULL_TVALUE);
	assert(m.add(1,1)==111);
	assert(m.add(10,10)==110);
	assert(m.add(-3,-3)==NULL_TVALUE);
	assert(m.size() == 5);
	assert(m.search(10) == 10);
	assert(m.search(16) == NULL_TVALUE);
	assert(m.remove(1) == 1);
	assert(m.remove(6) == NULL_TVALUE);
	assert(m.size() == 4);


	TElem e;
	MapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.getCurrent();
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 19);
	assert(s2 == 19);

	/*Map m2;
	m2.add(1, 2);
	m2.add(2, 3);
	m2.add(3, 1);
	m2.add(4, 5);
	MapIterator id2 = m2.iterator();
	Node* lastNode = id2.getCurrentNode();
	std::cout << "Forward traversal\n";
	while (id2.valid())
	{
		e = id2.getCurrent();
		std::cout << e.first << " : " << e.second << "\n";
		lastNode = id2.getCurrentNode();
		id2.next();
		
		
	}
	std::cout << "\nBackwards traversal\n";
	id2.setCurrentNode(lastNode);
	while (id2.valid())
	{
		e = id2.getCurrent();
		std::cout << e.first << " : " << e.second << "\n";
		id2.previous();
	}*/

}


