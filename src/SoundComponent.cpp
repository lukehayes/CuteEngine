#include "ECS/Component/SoundComponent.h"
#include <raylib.h>

namespace ECS
{
    SoundComponent::SoundComponent(const char* filename)
        : sound(LoadSound(filename))
    {}

    void
    SoundComponent::play() 
    {
        PlaySound(this->sound);
    }

    void
    SoundComponent::stop()
    {
        StopSound(this->sound);
    }

    void
    SoundComponent::pitch(float pitch)
    {
        SetSoundPitch(this->sound, pitch);
    }

    void
    SoundComponent::volume(float volume) 
    {
        SetSoundVolume(this->sound, volume);
    }
}
