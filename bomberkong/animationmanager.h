#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H


/**
 * @brief The AnimationManager class is used to track the current frame index in a spritesheet.
 */
class AnimationManager
{

private:
    int frameInterval; ///< Range of the used interval
    int timer;        ///< frame timer
    int frame;        ///< actual frame
    int startFrame;   ///< Starting Frame
    int endFrame;     ///< Ending Frame

public:
    AnimationManager();

    /**
     * @brief Sets the start and end frame of the animation
     * @param frameStart : the start frame
     * @param frameEnd : the end frame
     */
    void play(int frameStart, int frameEnd);

    /**
     * @brief Returns the current frame of the animation
     * @return The current animation frame
     */
    int getFrame();

    /**
     * @brief Sets the interval between each frame
     * @param interval The interval (in ticks)
     */
    void setInterval(int interval);

    /**
     * @brief Updates the state of the manager
     */
    void update();

};

#endif // ANIMATIONMANAGER_H
