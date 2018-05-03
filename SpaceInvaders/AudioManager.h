#include "SDL_mixer.h"

class AudioManager
{
public:
	AudioManager();
	void LoadMixer();
	void PlayMusic();
	void PlaySFX();
	void PauseMusic();
	void ResumeMusic();
	void CleanUp();
	~AudioManager();


private:

};