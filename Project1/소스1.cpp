#include <iostream>

using namespace std;

class Tile
{
private:
	int num;
	int x;
	int y;
	bool isOpen;
public:
	Tile()
	{
		num = 0;
		isOpen = false;
	}
	int getNum()
	{
		return num;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	bool isTileOpne()
	{
		return isOpen;
	}

	void SetNum(int num)
	{
		this->num = num;
	}
	void SetTileOpen(bool isOpen)
	{
		this->isOpen = isOpen;
	}
	void SetXY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class GameMap
{
private:
	Tile** map;
	int width;
	int height;
	int mineNum;

	void SetMapSize()
	{
		map = new Tile * [height]();
		for (int i = 0; i < height; i++)
		{
			map[i] = new Tile[width]();
		}
	}

	void SetMine()
	{
		srand(time(NULL));
		for (int i = mineNum; i > 0; i--)
		{
			int rx = rand() % width;
			int ry = rand() % height;

			if (map[ry][rx].getNum() == 9)
			{
				continue;
			}
			map[ry][rx].SetNum(9);
		}
	}

	void SetNum()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				map[i][j].SetXY(j, i);

				if(map[i][j].getNum() != 9)
				{
					for (int y = map[i][j].getY() - 1; y < map[i][j].getY() + 2; y++)
					{
						for (int x = map[i][j].getX() - 1; x < map[i][j].getX() + 2; x++)
						{
							if (y >= 0 && y < height && x >= 0 && x < width)
							{
								if (map[y][x].getNum() == 9)
								{
									map[i][j].SetNum(map[i][j].getNum() + 1);
								}
							}
						}
					}
				}
			}
		}
	}

public:
	GameMap(int width, int height, int mineNum)
	{
		this->width = width;
		this->height = height;
		this->mineNum = mineNum;

		SetMapSize();
		SetMine();
		SetNum();
	}

	void draw()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << map[i][j].getNum();
			}
			cout << endl;
		}
	}
};

int main()
{
	GameMap gameMap(16, 16, 5);
	gameMap.draw();
}