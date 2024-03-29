#ifndef DONKEYKONG_H
#define DONKEYKONG_H
#include "entity.h"
#include "animationmanager.h"
#include "flame.h"


/**
 * @brief The class of DonkeyKong, the game's boss
 */
class DonkeyKong : public Entity
{

private:
    QPixmap sprite;                 ///< The actual Sprite
    AnimationManager* animation;    ///< The actual animation
    int targetPos;                  ///< Pose where the DK send the next barrel
    int dist;                       ///< Distance to the next x where DK send barrel
    bool isThrowing;                ///< Is DK actally throwing a barrel
    int hp;

public:
    /**
     * @brief Create a DK
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    DonkeyKong(int posX, int posY, SceneType Lvl);

    /**
     * @brief Create a DK
     * @param pos : location coordinates
     */
    DonkeyKong(Coordinate pos , SceneType Lvl);

    /**
     * @brief Destructor for a DonkeyKong object
     */
    ~DonkeyKong();

    /**
     * @brief update the Donkey Kong (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual DK
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();


    void collisionEvent(Entity* body);

    int timer;///< init timer
    int throwingRate;

};

#endif // DONKEYKONG_H
