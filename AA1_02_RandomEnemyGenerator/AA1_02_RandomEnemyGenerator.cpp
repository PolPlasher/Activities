// AA1_02_RandomEnemyGenerator by Pol Lleida Ramírez & Pol Blesa Albiñana
#include "Enemy.h"

int main()
{
	const int MAX_ENEMIES = 5;
	Enemy enemies[MAX_ENEMIES];
	return 0;
}

std::string getEnemyType(EnemyType type)
{
	switch (type)
	{
	case EnemyType::ZOMBIE:
		return "Zombie";
	case EnemyType::VAMPIRE:
		return "Vampire";
	case EnemyType::GHOST:
		return "Ghost";
	case EnemyType::WITCH:
		return "Witch";
	}
}

bool equalEnemies(Enemy enemy1, Enemy enemy2)
{
	return (enemy1.type == enemy2.type && enemy1.name == enemy2.name);
}

Enemy createRandomEnemy()
{
	std::string randomNames[5] = { "Jovani Vazquez", "Jorge Nitales", "Elba Zurita", "Pau Rafel", "Oriol Ripoll" };

	Enemy randomEnemy;

	randomEnemy.type = static_cast<EnemyType>(rand() % 4);
	randomEnemy.name = randomNames[rand() % 5];
	randomEnemy.health = rand() % 100;
}