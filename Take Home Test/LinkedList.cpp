#include "LinkedList.h"

//code here references http://stackoverflow.com/questions/22141477/simple-linked-list-c

LinkedList::LinkedList() {
	head = NULL;
}

void LinkedList::addParticleToList(Particle particle) {

	node *n = new node();
	n->m_particle = particle;
	n->next = head;
	head = n;

}
