// SoundManager.cpp

#include "soundmanager.h"

SoundManager& SoundManager::getInstance() {
    static SoundManager instance;
    return instance;
}

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {
    for (QSoundEffect* soundEffect : soundMap.values()) {
        soundEffect->deleteLater();
    }
}

void SoundManager::loadSound(const QString& soundFilePath) {
    if (!soundMap.contains(soundFilePath)) {
        QSoundEffect* soundEffect = new QSoundEffect();
        soundEffect->setSource(QUrl::fromLocalFile(soundFilePath));
        soundEffect->setVolume(1.0);

        soundMap.insert(soundFilePath, soundEffect);
    }
}

void SoundManager::playSound(const QString& soundFilePath, qreal volume) {
    QSoundEffect* soundEffect = soundMap.value(soundFilePath);
    if (soundEffect) {
        if (!soundEffect->isPlaying()) {
            soundEffect->setVolume(volume);
            soundEffect->play();
        }
    }
}

