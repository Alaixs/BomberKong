#include "animationmanager.h"

AnimationManager::AnimationManager()
{
    frameInterval = 5;
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
    startFrame = frameStart;
    endFrame = frameEnd;
    timer = frameInterval;
    frame = frameStart;
}


void AnimationManager::update()
{
    timer--;
    if (timer == 0)
    {
        frame++;
        if (frame == endFrame)
        {
            frame = startFrame;
        }
        timer = frameInterval;
    }
}
