# Game OF Life

Данное приложение является реализацией известной игры [Game of Life](https://ru.wikipedia.org/wiki/Игра_«Жизнь»)

## Зависимости

При разработке приложения использовались библиотеки:
* SDL2 - для разработки графического интерфейса пользователя
* Boost - для парсинга аргументов командной строки

Ниже приведены инструкции по установке данных библиотек на ОС Ubuntu:

<b>Установка SDL2:</b>
```
sudo apt update
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
```

<b>Установка Boost:</b>
```
sudo apt update
sudo apt install libboost-all-dev
```

## Сборка и запуск приложения
```
git clone git@git.deviks.io:SerpentDragon/GameOfLife.git
cd GameOfLife
mkdir build
cd build
cmake ..
cmake --build .
```

Запуск приложения из терминала осущетвляется посредством команды:
```
GameOfLife [--help] [--width <width>] [--height <height>] [--speed <speed>]
```
запуск приложения может осуществляться с рядом опциональных аргументов:  
* --help (-H) - вывод справки   
* --width (-w) - ширина игрового поля в клетках
* --height (-h) - высота игрового поля в клетках
* --speed (-s) - скорость игры
