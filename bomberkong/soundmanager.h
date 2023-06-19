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
     * @param playMultipleTimes : Flag indicating if the sound can be played multiple at the same time  or no
     * @param looping : flag indicating if the sound should be looped
     */
    void playSound(const QString& soundFilePath, qreal volume, bool playMultipleTimes, bool looping);

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
     * @brief Map of sound initialize
     */
    QMap<QString, QSoundEffect*> soundMap;

};


#endif
