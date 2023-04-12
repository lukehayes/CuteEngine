#ifndef ECS_SOUND_COMP_H
#define ECS_SOUND_COMP_H

#include "ECS/Component/Component.h"
#include "raylib.h"

namespace ECS
{
  class SoundComponent : public Component
  {
  public:
      /**
       * Constructor.
       *
       * @param const char* filename    The sound file.
       *
       * @return void.
       */
      SoundComponent(const char* filename);

      /**
       * Destructor.
       */
      ~SoundComponent();

      /**
       * Play the sound file associated with this component.
       *
       * @return void.
       */
      void play();

      /**
       * Stop the sound associated with this component.
       *
       * @return void.
       */
      void stop();

      /**
       * Set the pitch of the sound.
       *
       * @param float pitch    The pitch of the sound - 1.0 is the default.
       *
       * @return void.
       */
      void pitch(float pitch);

      /**
       * Set the volume of the sound.
       *
       * @param float volume    The volume of the sound - 1.0 is the maximum.
       *
       * @return void.
       */
      void volume(float volume);

      void update(double dt) override {}

      Sound sound;

  };
}



#endif // ECS_SOUND_COMP_H
