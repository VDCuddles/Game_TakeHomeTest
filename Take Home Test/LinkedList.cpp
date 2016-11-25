#include "LinkedList.h"
#include "Game.h"

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

Particle LinkedList::popValue() {
	node *n = head;
	Particle ret = n->m_particle;
	head = head->next;
	delete n;
	return ret;
}

void LinkedList::displayAllParticles() {
	//head->m_particle.drawParticle(Game::getInstance()->getWindow());
}