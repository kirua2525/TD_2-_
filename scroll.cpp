#include "scroll.h"

void Scroll::Initialize(
	float screenScrollX,
	float screenMaxScroll
) {
	this->scrollX = screenScrollX;
	this->maxScroll = screenMaxScroll;
}

void Scroll::Update(Player player, Line line) {
	if (this->scrollX < 0) {
		this->scrollX = 0;
	}
	if (this->scrollX > this->maxScroll - 1280) {
		this->scrollX = this->maxScroll - 1280;
	}

	if (player.moveRight) {
		player.pos.x += player.velocity.x;

		line.isHitLine = player.pos.x + player.size.x > line.topPos.x + this->scrollX;

		if (line.isHitLine && this->scrollX < this->maxScroll - 1280) {
			this->scrollX += player.velocity.x;
		}
	}

	if (player.moveLeft) {
		player.pos.x -= player.velocity.x;

		line.isHitLine = player.pos.x + player.size.x < line.topPos.x + this->scrollX;

		if (line.isHitLine && this->scrollX < this->maxScroll - 1280 + line.topPos.x) {
			this->scrollX -= player.velocity.x;
		}
	}
}