// SoundManager.h
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QSoundEffect>
#include <QMap>

/**
 * @brief The class to manage any sound on game
 */
class SoundManager : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Get an instance of SoundManager
     * @return the instance of Sound Manager
     */
    static SoundManager& getInstance();

    /**
     * @brief Load a Sound
     * @param soundFilePath : path of the sound file
     */
    void loadSound(const QString& soundFilePath);

    /**
     * @brief Play a Sound
     * @param soundFilePath : path of the sound file
     * @param volume : the volume to choose
     * @param looping : flag indicating if the sound should be looped
     */
    void playSound(const QString& soundFilePath, qreal volume, bool looping);

    /**
     * @brief Stop a sounds who's playing
     */
    void stopSound(const QString& soundFilePath);


private:
    /**
     * @brief Create a SoundManager
     */
    SoundManager();

    /**
     * @brief Destructor of SoundManager
     */
    ~SoundManager();

    /**
     * @brief Play a Sound In a new Thread
     * @param soundEffect : the sound choose
     * @param volume : the volume choose
     */
    void playSoundInThread(QSoundEffect* soundEffect, qreal volume);
    QMap<QString, QSoundEffect*> soundMap;

};


#endif
