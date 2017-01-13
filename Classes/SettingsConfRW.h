#ifndef _SETTINGS_CONFIG_RW
#define _SETTINGS_CONFIG_RW

#include "core/config.h"
#define CONFIG_PATH "../Resources/config/settings.conf"

class SettingsConfRW
{
public:
	static bool readBGMusicPlaying();
	static void writeBGMusicPlaying(bool isPlaying);
	static float readBGMusicVolume();
	static void writeBGMusicVolume(float volume);
};

#endif //_SETTINGS_CONFIG_RW