#include "AdjList.h"

AdjList::AdjList(uint32_t vertexCount)
: mEdges(vertexCount)
{
}

void AdjList::addEdge(uint32_t u, uint32_t v, uint32_t w)
{
	mEdges[u].insert(std::make_pair(v, w));
}

uint32_t AdjList::getEdgeWeight(uint32_t u, uint32_t v) const
{
	// TODO
	return 0;
}

std::vector<uint32_t> AdjList::getAllIncoming(uint32_t u) const
{
	std::vector<uint32_t> in;
	// TODO
	return in;
}

std::vector<uint32_t> AdjList::getAllOutgoing(uint32_t u) const
{
	std::vector<uint32_t> out;
	// TODO
	return out;
}