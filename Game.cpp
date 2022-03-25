#include "stdafx.h"
#include "Game.h"

void Game::init()
{
	for (int i = 0; i < 400; i++) {
		Targets[i] = Boid();
	}

	for (int i = 0; i < 20; i++) {
		snake[i] = Segment();
		snake[i].setter(400, 400, 5);
	}
}

void Game::update(int& state, int& score, int& health, colorScheme* colors)
{
	if (score == 0)
		Start = TRUE;

	updateTowers(colors);
	updateTargets(score, health);
	updateSnake(colors);
	sprintf(displayNumBoids, "Enemy : %d", numBoids);

	if (!setting)
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_START))
			state = 5;
}

void Game::draw()
{
	for (int i = 0; i < numSpikeTowers; i++) {
		spikeTowers[i].draw(drawTool);
	}

	for (int i = 0; i < numMaceTowers; i++) {
		maceTower[i].draw(drawTool);
	}

	for (int i = 0; i < numFlameThrowers; i++) {
		flameThrowers[i].draw(drawTool);
	}

	for (int i = 0; i < numSlowTowers; i++) {
		slowTowers[i].draw(drawTool);
	}

	for (int i = 0; i < numWalls; i++) {
		walls[i].draw(drawTool);
	}

	for (int i = 0; i < 200; i++) {
		Targets[i].draw();
	}

	drawTool->shape3D(snakeX, snakeY, 12, PI / 4, 0, snakeHeadAngle, 3, snakeR, snakeG, snakeB);
	for (int i = 1; i < 20; i++) {
			float bodyAngle = atanf((snake[i - 1].getY() - snake[i].getY()) / (snake[i - 1].getX() - snake[i].getX()));
			drawTool->shape3D(snake[i].getX(), snake[i].getY(), 2 + (20 - i) / 2, PI / 4, 0, bodyAngle + PI / 4, 4, snakeR, snakeG, snakeB);
		
	}

	App::Print(900, 700, displayNumBoids);
}


void Game::createTower(int type)
{
	if (numSpikeTowers < 50 && type == 1) {
		numSpikeTowers++;
	}
	else if (numMaceTowers < 50 && type == 2) {
		numMaceTowers++;
	}
	else if (numSlowTowers < 2 && type == 3) {
		numSlowTowers++;
	}
	else if (numFlameThrowers < 50 && type == 4) {
		numFlameThrowers++;
	}
	
}

void Game::createWall()
{
	numWalls++;
}

void Game::endGame()
{
	delete drawTool;
}

void Game::moveSnake()
{
	if ((App::GetController().GetLeftThumbStickX()) != 0) {
		snakeHeadAngle = atanf((App::GetController().GetLeftThumbStickY()) / (App::GetController().GetLeftThumbStickX()));
		if ((App::GetController().GetLeftThumbStickX() < 0))
			snakeHeadAngle += PI;
	}

	if (abs(App::GetController().GetLeftThumbStickX()) > 0.1) {
		snakeX += App::GetController().GetLeftThumbStickX() * 10;
		if (snakeX > 1150)
			snakeX = 0;
		if (snakeX < -100)
			snakeX = 1050;
	}
	if (abs(App::GetController().GetLeftThumbStickY()) > 0.1) {
		snakeY += App::GetController().GetLeftThumbStickY() * 10;
		if (snakeY > 850)
			snakeY = 0;
		if (snakeY < -100)
			snakeY = 750;
	}
}

void Game::updateTargets(int& score, int& health)
{
	if (Start) {
		for (int i = 0; i < numBoids; i++) {
			for (int j = 0; j < numSpikeTowers; j++) {
				Targets[i].run(spikeTowers[j].getX(), spikeTowers[j].getY(), 30);
			}
			for (int j = 0; j < numFlameThrowers; j++) {
				Targets[i].run(flameThrowers[j].getX(), flameThrowers[j].getY(), 30);
			}
			for (int j = 0; j < numMaceTowers; j++) {
				Targets[i].run(maceTower[j].getX(), maceTower[j].getY(), 30);
			}
			for (int j = 0; j < numSlowTowers; j++) {
				Targets[i].run(slowTowers[j].getX(), slowTowers[j].getY(), 30);
			}

			for (int j = 0; j < numWalls; j++) {
				float x = walls[j].getX();
				float y = walls[j].getY();
				float xInc = (walls[j].getX2() - x) / 250;
				float yInc = (walls[j].getY2() - y) / 250;
				for (int z = 0; z < 250; z++) {
					Targets[i].run(x + z * xInc, y + z * yInc, 10);
				}
			}

			for (int y = 0; y < 20 - 1; y++) {
				Targets[i].run(snake[y].getX(), snake[y].getY(), 20);
			}

			Targets[i].update(Targets, numBoids, score, health);
		}
	}
}

void Game::updateTowers(colorScheme* colors)
{
	setting = FALSE;
	for (int i = 0; i < numSpikeTowers; i++) {
		spikeTowers[i].setColor(colors->getColor1r(), colors->getColor1g(), colors->getColor1b());
		if (!spikeTowers[i].isSet()) {
			spikeTowers[i].setTooCloseFalse();
			spikeTowers[i].checkLocation(spikeTowers, numSpikeTowers - 1);
			spikeTowers[i].checkLocation(maceTower, numMaceTowers);
			spikeTowers[i].checkLocation(slowTowers, numSlowTowers);
			spikeTowers[i].checkLocation(flameThrowers, numFlameThrowers);
		}
		spikeTowers[i].update();
		spikeTowers[i].aim(Targets);
		spikeTowers[i].checkHit(Targets);
		if (!spikeTowers[i].isSet())
			setting = TRUE;
	}

	for (int i = 0; i < numMaceTowers; i++) {
		maceTower[i].setColor(colors->getColor2r(), colors->getColor2g(), colors->getColor2b());
		if (!maceTower[i].isSet()) {
			maceTower[i].setTooCloseFalse();
			maceTower[i].checkLocation(spikeTowers, numSpikeTowers);
			maceTower[i].checkLocation(maceTower, numMaceTowers - 1);
			maceTower[i].checkLocation(slowTowers, numSlowTowers);
			maceTower[i].checkLocation(flameThrowers, numFlameThrowers);
		}
		maceTower[i].update();
		maceTower[i].checkHit(Targets);
		if (!maceTower[i].isSet())
			setting = TRUE;
	}

	for (int i = 0; i < numFlameThrowers; i++) {
		flameThrowers[i].setColor(colors->getColor3r(), colors->getColor3g(), colors->getColor3b());
		if (!flameThrowers[i].isSet()) {
			flameThrowers[i].setTooCloseFalse();
			flameThrowers[i].checkLocation(spikeTowers, numSpikeTowers);
			flameThrowers[i].checkLocation(maceTower, numMaceTowers);
			flameThrowers[i].checkLocation(slowTowers, numSlowTowers);
			flameThrowers[i].checkLocation(flameThrowers, numFlameThrowers - 1);
		}
		flameThrowers[i].update();
		flameThrowers[i].aim(Targets);
		flameThrowers[i].checkHit(Targets);
		if (!flameThrowers[i].isSet())
			setting = TRUE;
	}

	for (int i = 0; i < numSlowTowers; i++) {
		slowTowers[i].setColor(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		if (!slowTowers[i].isSet()) {
			slowTowers[i].setTooCloseFalse();
			slowTowers[i].checkLocation(spikeTowers, numSpikeTowers);
			slowTowers[i].checkLocation(maceTower, numMaceTowers);
			slowTowers[i].checkLocation(slowTowers, numSlowTowers - 1);
			slowTowers[i].checkLocation(flameThrowers, numFlameThrowers);
		}
		slowTowers[i].update();
		slowTowers[i].checkHit(Targets);
		if (!slowTowers[i].isSet())
			setting = TRUE;
	}

	for (int i = 0; i < numWalls; i++) {
		walls[i].setLocation();
		if (!walls[i].isSet())
			setting = TRUE;
	}
}

void Game::updateSnake(colorScheme* colors)
{
	if (!setting)
		moveSnake();

	snake[0].update(snakeX, snakeY, 15);
	for (int i = 1; i < 20; i++) {
		snake[i].update(snake[i - 1].getX(), snake[i - 1].getY(), 15);
	}

	snakeR = colors->getColor5r();
	snakeG = colors->getColor5g();
	snakeB = colors->getColor5b();
}

