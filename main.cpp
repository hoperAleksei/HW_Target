#include <iostream>
#include <random>
#include <cmath>

using namespace std;

float randCoord(float coord)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(-5, 5);
	return  coord + float(dist(gen));
}

float getShotRad()
{
	float x, y;
	cout << "Ведите координату x выстрела: ";
	cin >> x;
	cout << "Ведите координату y выстрела: ";
	cin >> y;

	x = randCoord(x);
	y = randCoord(y);

	cout << "Вы попали в точку: (" << x << "; " << y << ")" << endl;

	return sqrt(x*x + y*y);
}

int getShotScore(float Rad)
{
	int res = 5 - floor(Rad);
	return res > 0 ? res : 0;
}

void game()
{
	int resScore = 0;
	int score;
	
	for (int i = 0; i < 5; i++)
	{
		score = getShotScore(getShotRad());
		cout << "За этот выстрел вы получили " << score << " очков!" << endl;
		resScore += score;
	}
	cout << "По итогу вы получили " << resScore << " очков" << (resScore < 10 ? ", поэтому вы ЛУЗЕР!" : ".") << endl;
}

int main() {
	game();
	return 0;
}