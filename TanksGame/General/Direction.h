#pragma once

enum class Direction {
	Up = 0b0001, Right = 0b0010, Down = 0b0100, Left = 0b1000
};

enum class MovingDirection {
	Up = 0b0001, Right = 0b0010, Down = 0b0100, Left = 0b1000, None = 0b0000
};