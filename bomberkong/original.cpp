#include "original.h"

Original::Original(QWidget* widget)
    : Level(widget)
{
    currentMap.push_back(rand()%3);
    restart();
}

void Original::restart()
{
    deleteAllEntity();

    // Loads data from a file
    std::ifstream levelDataFile;
    levelDataFile.open("../bomberkong/assets/maps/Map.bkmap");

    if (!levelDataFile.is_open())
        qDebug() << "Could not open the file";


    // Iterate on every character of the file and place the corresponding block,
    // Goes on the next line when encountering a semicolon;
    char block;

    for(int i = 0; i < currentMap.at(0); i++)
    {
        while(levelDataFile >> block && block != '!'){};
    }

    int yPos = 4 * cellSize;
    int xPos = 0;

    while (levelDataFile >> block && block != '!')
    {
        if (block == ';')
        {
            // Line break
            yPos += cellSize;
            xPos = 0;

        }
        else
        {
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos));
            }

            xPos += cellSize;
        }
    }

    levelDataFile.close();

    // Create characters at their spawn points
    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize));
    createEntity(new DonkeyKong(9 * cellSize, 0));
}
