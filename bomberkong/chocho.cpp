#include "chocho.h"

#include "hammer.h"
#include "RNG.h"

Chocho::Chocho(QWidget * widget)
    : Level(widget)

{
    itsSceneType = CHOCHO;
    setOffsetLimit(21 * cellSize, -20 * 2 * cellSize);

    currentMap.push_back(RNG::randomInt(0, 2));
    currentMap.push_back(RNG::randomInt(0, 2));
    currentMap.push_back(RNG::randomInt(0, 2));

    initPowerUpGUI();
    restart();
}

Chocho::Chocho(QWidget * widget, PlayerCharacter * player)
    : Level(widget)

{
    *itsPlayer = *player;
    itsPlayer->setParent(this);

    itsSceneType = CHOCHO;
    setOffsetLimit(21 * cellSize, -20 * 2 * cellSize);

    currentMap.push_back(rand() % 3);
    currentMap.push_back(rand() % 3);
    currentMap.push_back(rand() % 3);

    initPowerUpGUI();

    // Update the GUI based on the player stats
    updateLivesGUI(itsPlayer->getItsLivesNb());
    updatePowerUpGUI(itsPlayer->getItsPUNumber(SPEED),SPEED);
    updatePowerUpGUI(itsPlayer->getItsPUNumber(BOMB_TIME),BOMB_TIME);
    updatePowerUpGUI(itsPlayer->getItsPUNumber(BOMB_RANGE),BOMB_RANGE);
    updatePowerUpGUI(itsPlayer->getItsPUNumber(BOMB_NB),BOMB_NB);
    updatePowerUpGUI(itsPlayer->getItsPUNumber(ARMOR),ARMOR);

    restart();
}

void Chocho::restart()
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
            // places the corresponding object
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos, itsSceneType));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos, itsSceneType));
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
            // places the corresponding object
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos, itsSceneType));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos, itsSceneType));
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
            // places the corresponding object
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos, itsSceneType));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos, itsSceneType));
            }

            xPos += cellSize;
        }
    }

    levelDataFileBottom.close();

    // Create characters at their spawn points
    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize - 20 * 2 * cellSize));

    DonkeyKong * dk = new DonkeyKong(9 * cellSize, - 20 * 2 * cellSize, itsSceneType);
    dk->throwingRate = 400;
    dk->setParent(this);
    entities.push_back(dk);

    createEntity(new Hammer(14 * cellSize, 20 * cellSize));
}


void Chocho::win()
{
    // Open the save menu and go to the next level (Glagla)
    dynamic_cast<Widget*>(root)->saveGame(1, itsPlayer);
}
