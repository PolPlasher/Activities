// AA1_02_RandomEnemyGenerator by Pol Lleida Ramírez & Pol Blesa Albiñana
#include "Enemy.h"

int main()
{
	const int MAX_ENEMIES = 5;
	Enemy enemies[MAX_ENEMIES];

	for (int i = 0; i < MAX_ENEMIES; i++)	// Iterate over enemies[MAX_ENEMIES]
	{
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			bool isEqual = true;
		}
			enemies[i] = createRandomEnemy();
	}

	std::cout << "List of enemies:" << std::endl;
	
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		std::cout << enemies[i].name << " is a " << getEnemyType(enemies[i].type) << " whose life is " << enemies[i].health << std::endl;
	}
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

	randomEnemy.type = static_cast<EnemyType>(rand() % 4);	// Pick a random enum element by casting a random 1 to 4 number into an EnemyType
	randomEnemy.name = randomNames[rand() % 5];	// Pick a random string from randomNames[5]
	randomEnemy.health = rand() % 100 + 1; // Pick a random value from 1 to 100
	
	return randomEnemy;
}