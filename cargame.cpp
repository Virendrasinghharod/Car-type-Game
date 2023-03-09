#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, obstacleX, obstacleY, score;
enum eDirection { STOP = 0, LEFT, RIGHT };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height - 1;
    obstacleX = rand() % width;
    obstacleY = 0;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == y && j == x) {
                cout << "O";
            }
            else if (i == obstacleY && j == obstacleX) {
                cout << "*";
            }
            else {
                cout << " ";
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }
    if (x < 0 || x > width-1) {
        gameOver = true;
    }
    if (obstacleY == y && obstacleX == x) {
        gameOver = true;
    }
    score++;
    obstacleY++;
    if (obstacleY > height) {
        obstacleX = rand() % width;
        obstacleY = 0;
    }
}

int main() {
    cout << "Welcome to the Car Racing Game!" << endl;
    cout << "Instructions:" << endl;
    cout << "Use the 'a' and 'd' keys to move your car left and right." << endl;
    cout << "Avoid hitting the obstacles represented by '*'. " << endl;
    cout << "Press 'x' to exit the game." << endl;
    cout << endl;
    
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    return 0;
}

