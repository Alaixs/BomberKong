#include "reloaded.h"
#include "hammer.h"

Reloaded::Reloaded(QWidget* widget)
    : Level(widget)
{
    itsSceneType = RELOADED;
    setOffsetLimit(21 * cellSize, -20 * 2 * cellSize);

    currentMap.push_back(rand() % 3);
    currentMap.push_back(rand() % 3);
    currentMap.push_back(rand() % 3);

    initPowerUpGUI();
    restart();
}

void Reloaded::restart()
{
    deleteAllEntity();

    // Loads data from a file
    std::ifstream levelDataFileBottom, levelDataFileMiddle, levelDataFileTop;
    levelDataFileBottom.open("../bomberkong/assets/maps/BAS_Reloaded.bkmap");
    levelDataFileMiddle.open("../bomberkong/assets/maps/MILIEU_Reloaded.bkmap");
    levelDataFileTop.open("../bomberkong/assets/maps/HAUT_Reloaded.bkmap");

    if (!levelDataFileTop.is_open() || !levelDataFileMiddle.is_open() || !levelDataFileBottom.is_open())
        qDebug() << "Could not open the file";


    // Iterate on every character of the file and place the corresponding block,
    // Goes on the next line when encountering a semicolon;
    char block;

    for(int i = 0; i < currentMap.at(0); i++)
    {
        while(levelDataFileBottom >> block && block != '!'){};
    }

    for(int i = 0; i < currentMap.at(1); i++)
    {
        while(levelDataFileMiddle >> block && block != '!'){};
    }

    for(int i = 0; i < currentMap.at(2); i++)
    {
        while(levelDataFileTop >> block && block != '!'){};
    }

    int yPos = 4 * cellSize - 20 * 2 * cellSize;
    int xPos = 0;

    while (levelDataFileTop >> block && block != '!')
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

    levelDataFileTop.close();


    while (levelDataFileMiddle >> block && block != '!')
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

    levelDataFileMiddle.close();

    while (levelDataFileBottom >> block && block != '!')
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

    levelDataFileBottom.close();

    // Create characters at their spawn points
    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize - 20 * 2 * cellSize));
    createEntity(new DonkeyKong(9 * cellSize, - 20 * 2 * cellSize));
    createEntity(new Hammer(14 * cellSize, 20 * cellSize));
}
