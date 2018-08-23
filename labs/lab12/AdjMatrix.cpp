#include "AdjMatrix.h"

AdjMatrix::AdjMatrix(uint32_t vertexCount)
: mEdges(vertexCount, std::vector<uint32_t>(vertexCount, 0))
{
}

void AdjMatrix::addEdge(uint32_t u, uint32_t v, uint32_t w)
{
	mEdges[u][v] = w;
}

uint32_t AdjMatrix::getEdgeWeight(uint32_t u, uint32_t v) const
{
	// TODO
	return 0;
}

std::vector<uint32_t> AdjMatrix::getAllIncoming(uint32_t u) const
{
	std::vector<uint32_t> in;
	// TODO
	return in;
}

std::vector<uint32_t> AdjMatrix::getAllOutgoing(uint32_t u) const
{
	std::vector<uint32_t> out;
	// TODO
	return out;
}