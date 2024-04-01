#include <common.h>
#include <bg_colors.h>

const RedGreen bg_color = {0x00, 0x50};

#define STATE_BONKING 0xC

bool should_update_bg_color = true;


enum{
    TIMER_STOPPED,
    TIMER_STARTED
};
int should_reset_timer = 0;

//This runs The Adventure Begins cutscene
void SkipIntro()
{
    _isPastTitleScreen = TRUE;                            //? This flag is checked by TheAdventureBeings() before it runs, so we must set this flag to TRUE.
    TheAdventureBegins();                                 //Call The Adventure Begins cutscene sequence      
}

//This function clears the bitflags for which collectables should spawn into a level/homeworld with spyro. This is the same area that the memory card writes to when loading a game.
void ResetLevelCollectables()
{
    memset(&_collectablesBitflags, 0, 0x4B0);
    for (int i = 0; i < 35; i++)
    {
        _levelGemsCollectedArray[i] = 0;
    }

    // Key Glitch Fix
    _keyState = 0;
    _ptr_keyChestHostGem = NULL;
}

//Changing asm instructions for pause menu RGB. Cannot change B value, as the value is in a shared register with other crucial parts of the struct.
inline void SetTitleScreenColor(byte r, byte g)
{
    *(short*)(0x8001A674) = r;
    *(short*)(0x8001A67C) = g;
}

//! Main Basic Checks
void MainUpdate()
{
    
    //Change background color when menu gets updated
    if(should_update_bg_color)
    {
        SetTitleScreenColor(bg_color.r, bg_color.g);
        should_update_bg_color = false;
    }
    
    //Main Loop
    if(_gameState == GAMESTATE_GAMEPLAY)
    {
        if (should_reset_timer == TIMER_STOPPED)
        {
            // Reset Conditions
            if (_spyro.state == STATE_BONKING || _spyro.health < 3 || _globalLives < 4 || _dragonTouchSpeed > 0x65)
            {
                should_reset_timer = TIMER_STARTED;
            }
        }

        // Reset
        else if (should_reset_timer >= 6)
        {
            SkipIntro();
            ResetLevelCollectables();
            should_reset_timer = TIMER_STOPPED;
            _dragonTouchSpeed = 0;
        }

        // Start timer to prepare for reset
        else if (should_reset_timer >= TIMER_STARTED)
        {
            should_reset_timer++;
        }
        
    }


}