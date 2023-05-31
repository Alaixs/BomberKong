#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H


class AnimationManager
{

private:
    int frameInterval;
    int timer;
    int frame;
    int startFrame;
    int endFrame;

public:
    AnimationManager();

    void play(int frameStart, int frameEnd);
    int getFrame();
    void setInterval(int interval);
    void update();

};

#endif // ANIMATIONMANAGER_H
