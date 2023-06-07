// SoundManager.h
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QSoundEffect>
#include <QMap>
#include <QThread>


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
     * @param volume : the volume choose
     */
    void playSound(const QString& soundFilePath, qreal volume);

    /**
     * @brief Stop All Sounds
     */
    void stopAllSounds();


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
