#include "animationmanager.h"


AnimationManager::AnimationManager(const int interval)
{
    frameInterval = interval;
}

AnimationManager::~AnimationManager()
{

}

void AnimationManager::setInterval(int interval)
{
    frameInterval = interval;
}


int AnimationManager::getFrame()
{
    return frame;
}


void AnimationManager::play(int frameStart, int frameEnd)
{
    if (frameStart != startFrame || frameEnd != endFrame)
    {
        // Sets the frame range
        startFrame = frameStart;
        endFrame = frameEnd;

        // Places itself at the beginning of the animation
        timer = frameInterval;
        frame = frameStart;
    }
}


void AnimationManager::update()
{
    timer--;
    if (timer == 0)
    {
        // Goes to next frame and loop if needed
        frame++;
        if (frame == endFrame)
        {
            frame = startFrame;
        }

        // Reset timer
        timer = frameInterval;
    }
}
