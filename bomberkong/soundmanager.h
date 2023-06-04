// SoundManager.h
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QSoundEffect>
#include <QMap>
#include <QThread>

class SoundManager : public QObject {
    Q_OBJECT

public:
    static SoundManager& getInstance();
    void loadSound(const QString& soundFilePath);
    void playSound(const QString& soundFilePath, qreal volume);
    void stopAllSounds();

private:
    SoundManager();
    ~SoundManager();
    void playSoundInThread(QSoundEffect* soundEffect, qreal volume);

    QMap<QString, QSoundEffect*> soundMap;
};



#endif
