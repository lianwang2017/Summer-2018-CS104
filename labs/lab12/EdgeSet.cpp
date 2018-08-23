#include "EdgeSet.h"

void EdgeSet::addEdge(uint32_t u, uint32_t v, uint32_t w)
{
	mEdges.insert(std::make_pair(Edge(u, v), w));
}

uint32_t EdgeSet::getEdgeWeight(uint32_t u, uint32_t v) const
{
	// TODO
	return 0;
}

std::vector<uint32_t> EdgeSet::getAllIncoming(uint32_t u) const
{
	std::vector<uint32_t> in;
	// TODO
	return in;
}

std::vector<uint32_t> EdgeSet::getAllOutgoing(uint32_t u) const
{
	std::vector<uint32_t> out;
	// TODO
	return out;
}

bool EdgeSet::Edge::operator<(const EdgeSet::Edge& rhs) const
{
	return mFrom < rhs.mFrom || (mFrom == rhs.mFrom && mTo < rhs.mTo);
}