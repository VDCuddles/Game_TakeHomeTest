#include <SFML/Graphics.hpp>
#include "Particle.h"
#pragma once

class LinkedList
{

	struct node {
		Particle m_particle;
		node *next;
	};

private:

	node *head;

public:

	LinkedList();
	void addParticleToList(Particle particle);

};


