// AA1_02_RandomEnemyGenerator by Pol Lleida Ramírez & Pol Blesa Albiñana
#include "Enemy.h"

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

bool equalEnemies(Enemy enemy1, Enemy enemy2)	// Returns true if the enemies are the same
{
	return (enemy1.type == enemy2.type && enemy1.name == enemy2.name);
}

Enemy createRandomEnemy()
{
	std::string randomNames[6] = { "Jovani Vazquez", "Jorge Nitales", "Elba Zurita", "Pau Rafel", "Oriol Ripoll" , "Alfredito Ugarte" };

	Enemy randomEnemy;

	randomEnemy.type = static_cast<EnemyType>(rand() % 4);	// Pick a random enum element by casting a random 1 to 4 number into an EnemyType
	randomEnemy.name = randomNames[rand() % 6];	// Pick a random string from randomNames
	randomEnemy.health = rand() % 100 + 1;	// Pick a random value from 1 to 100

	return randomEnemy;
}

int main()
{
	const int MAX_ENEMIES = 5;
	Enemy enemies[MAX_ENEMIES];

	srand(time(NULL));	// Initializate random seed

	// ENEMIES GENERATION
	bool isRepeated;
	do {
		isRepeated = false;
		for (int i = 0; i < MAX_ENEMIES; i++)	// Iterate over enemies
		{
			enemies[i] = createRandomEnemy();
			for (int j = 0; j < MAX_ENEMIES; j++)	// Compare each enemy with the others
			{
				if (i != j)	// Exclude comparing with himself (would return true)
				{
					if (equalEnemies(enemies[i], enemies[j]))	// Compare the two enemies
					{
						isRepeated = true;
						break;
					}
				}
			}
			if (isRepeated) break;
		}
	} while (isRepeated);	// Repeat the process until each enemy is unique

	//	PRINT
	std::cout << "List of enemies:" << std::endl;

	for (Enemy enemy : enemies)	// Range-based for printing each enemy
	{
		std::cout << enemy.name << " is a " << getEnemyType(enemy.type) << " whose life is " << enemy.health << std::endl;
	}
	return 0;
}