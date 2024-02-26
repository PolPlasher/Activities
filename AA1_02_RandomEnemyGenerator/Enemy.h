#pragma once
#include <iostream>

enum class EnemyType
{
	ZOMBIE,
	VAMPIRE,
	GHOST,
	WITCH
};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

std::string getEnemyType(EnemyType type);
bool equalEnemies(Enemy enemy1, Enemy enemy2);
Enemy createRandomEnemy();