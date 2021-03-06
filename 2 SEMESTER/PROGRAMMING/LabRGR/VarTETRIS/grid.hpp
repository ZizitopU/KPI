#pragma once



class Block;
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "block.hpp"
//Размеры игрового поля
#define W 10
#define H 22

using namespace sf;


//Базовые типи блоков
const int types[7][5][4] {

{ //I
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {4,0,0,0}
},
{
    {1,0,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
    {3,0,0,0}
},
{
    {0,0,1,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
    {3,0,0,0}
},
{
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0},
    {4,0,0,0}
},
{
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {3,0,0,0}
},
{
    {0,1,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
    {3,0,0,0}
},
{
    {1,1,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
    {3,0,0,0}
},

};
//Класс игрового поля
class Grid{
public:
    int cellsize = 20;//Размер клетки в пикселях
    int x = 10,y = 10;//Позиция поля на экране
    int score = 0;//Игровой счет
    int** field; //Матрица заполненности поля
    int next = 0;//Номер следущей падающей фигуры
    Block* falling;//Указатель на объект падающей фигуры
    RenderWindow* window;//Указатель на окно для рисования


    Grid(RenderWindow&);
    ~Grid();
    void draw();//Метод отрисовки поля
    void fillBlock(int,int,int);//Метод закрашиваня одной клетки(принимает позицию в матрице и цвет)
    void drawPreview();//Метод для рисования следующего блока сбоку от поля
    bool update();//Обновления игровой логики
    void handleKey(Event&);//Обработка клавиш
    bool checkCollision(Block*);//Проверка на то может ли фигура располагаться в своей позиции
    void finalize();//Фиксирование текущей падающей фигуры на поле
};
















