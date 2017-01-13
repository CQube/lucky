#include "SettingsConfRW.h"
#include <io.h>

bool SettingsConfRW::readBGMusicPlaying()
{
	if (!(_access(CONFIG_PATH, 0) == -1)) {
		std::string temp = dConf::getValueByKey(CONFIG_PATH, "is_background_music_playing");
		return dConf::stringToBool(temp);
	}
	return false;
}

void SettingsConfRW::writeBGMusicPlaying(bool isPlaying)
{
	if (!(_access(CONFIG_PATH, 0) == -1)) {
		std::string temp = dConf::boolToString(isPlaying);
		dConf::setValueByKey(CONFIG_PATH, "is_background_music_playing", temp);
	}
}

float SettingsConfRW::readBGMusicVolume()
{
	if (!(_access(CONFIG_PATH, 0) == -1)) {
		std::string temp = dConf::getValueByKey(CONFIG_PATH, "background_music_volume");
		return atof(temp.c_str());
	}
	return 1.0;
}

void SettingsConfRW::writeBGMusicVolume(float volume)
{
	if (!(_access(CONFIG_PATH, 0) == -1)) {
		dConf::setValueByKey(CONFIG_PATH, "background_music_volume", std::to_string(volume));
	}
}