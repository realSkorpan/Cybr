#include "TilemapGenerator.h"

TilemapGenerator::TilemapGenerator() {
}

TilemapGenerator::~TilemapGenerator() {
	for (int i = 0; i < nodes.size(); ++i) {
		delete nodes[i];
	}
	for (int i = 0; i < rooms.size(); ++i) {
		delete rooms[i];
	}
}

void TilemapGenerator::generateTilemap(int cols, int rows, int width, int height, int depth) {
	block.resize(rows);
	for (int i = 0; i < rows; i++) {
		block[i].resize(cols);
	}

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			block[r][c] = generateBlock(width, height, depth);
		}
	}
}

Tilemap* TilemapGenerator::generateBlock(int width, int height, int depth) {
	Tilemap *tm = new Tilemap(width, height);
	BSPNode *block = new BSPNode();

	block->col = 0;
	block->row = 0;
	block->width = width;
	block->height = height;

	int curDepth = 0;
	if (curDepth < depth)
		splitNode(block, curDepth, depth);

	//this->createRooms(tm);

	return tm;
}

void TilemapGenerator::splitNode(BSPNode *node, int curDepth, int maxDepth) {
	node->A = new BSPNode;
	node->B = new BSPNode;
	node->depth = curDepth;
	// horizontal (=0) or vertical (=1) split
	bool hSplit = ((rand() % 2) == 0);
	if (hSplit) {
		std::cout << "h split" << "\n";
		// set length, breakpoint.
		int min = (int)(0.6 * node->height);
		int max = (int)(0.6 * node->height);
		int rowline = ((rand() % (max - min + 1)) + min);
		// set properties of subnodes.
		node->A->col = node->col;
		node->A->row = node->row;
		node->A->width = node->width;
		node->A->height = (rowline + 1);

		node->B->col = node->col;
		node->B->row = node->A->row + (rowline + 1);
		node->B->width = node->width;
		node->B->height = node->height - node->A->height;
	}
	else {
		std::cout << "v split" << "\n";
		int min = (int)(0.6 * node->width);
		int max = (int)(0.6 * node->width);
		int colline = ((rand() % (max - min + 1)) + min);

		node->A->col = node->col;
		node->A->row = node->row;
		node->A->width = (colline + 1);
		node->A->height = node->height;

		node->B->col = node->A->col + (colline + 1);
		node->B->row = node->row;
		node->B->width = node->width - node->A->width;
		node->B->height = node->height;
	}
	// recursively rerun function
	if (curDepth < maxDepth) {
		splitNode(node->A, (curDepth + 1), maxDepth);
		splitNode(node->B, (curDepth + 1), maxDepth);
	}
	else {
		this->rooms.push_back(node->A);
		this->rooms.push_back(node->B);
	}
}

void TilemapGenerator::createRooms(Tilemap *tmap) {
	for (int i = 0; i < rooms.size(); ++i) {
		BSPNode *node = this->rooms[i];

		sf::Color fill = sf::Color(150, 150, 150);
		sf::Color outline = sf::Color(0, 0, 0, 40);
		for (int r = node->row; r < (node->row + node->height); ++r) {
			for (int c = node->col; c < (node->col + node->width); ++c) {
				tmap->getTile(r, c)->setColor(fill, outline);
			}
		}
	}
}

void TilemapGenerator::printBlock(int width, int height) const {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			std::cout << rooms[y][x].depth;
		}
		std::cout << std::endl;
	}
}