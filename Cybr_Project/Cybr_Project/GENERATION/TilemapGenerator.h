#pragma once
#include <iostream>
#include <vector>
#include "Tilemap.h"

struct BSPNode {
	BSPNode *A;
	BSPNode *B;
	int col, row, width, height, depth;
};

class TilemapGenerator {
private:
	//std::vector<std::vector<BSPNode*>> nodes;
	std::vector<BSPNode*> nodes;
	std::vector<BSPNode*> rooms;
	std::vector<std::vector<Tilemap*>> block;
public:
	TilemapGenerator();
	~TilemapGenerator();

	void generateTilemap(int cols, int rows, int width, int height, int depth);
	Tilemap* generateBlock(int width, int height, int depth);
	void splitNode(BSPNode *node, int curDepth, int maxDepth);
	void createRooms(Tilemap *tm);
	void printBlock(int width, int height) const;
};