

#include "stdafx.h"
#include "SoundManager.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <SDL.h>

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch = NULL;

SoundManager::SoundManager()
{
	/*loadMusic();
	Mix_PlayMusic(gMusic, -1);*/
	playSound("Sounds/scratch.wav");
	playMusic("Sounds/beat.wav");
	Mix_PlayChannel(-1, gScratch, 0);
}


SoundManager::~SoundManager()
{
	freeSound();
	freeMusic();
	Mix_Quit();
}
void SoundManager::initialize()
{

	

	//Initialize SDL
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		
	}
	//Initialize SDL_mixer
	else if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		{
			OutputDebugString(L"*****************AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA***************************");
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		}
	}

	CreateSingleton();

}

void SoundManager::update()
{

}

bool SoundManager::loadSound(std::string sound)
{
	//Loading success flag
	bool success = true;
	

	//Load sound effects
	gScratch = Mix_LoadWAV(sound.c_str());

	if (gScratch == NULL)
	{
		OutputDebugString(L"*****************SOUND NOT LOADED***************************");
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	return success;
}
bool SoundManager::loadMusic(std::string music)
{
	//Loading success flag
	bool success = true;



	//Load music
	gMusic = Mix_LoadMUS(music.c_str());
	
	if (gMusic == NULL)
	{
		OutputDebugString(L"*****************MUSIC NOT LOADED***************************");
		//Console.Error.WriteLine("MUSIC NOT LOADED");
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

void SoundManager::freeSound()
{
	//Free the sound effects
	Mix_FreeChunk(gScratch);
	gScratch = NULL;
}

void SoundManager::freeMusic()
{
	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
}

void SoundManager::playSound(std::string soundName)
{
	loadSound(soundName);
}
void SoundManager::playMusic(std::string soundMusic)
{
	loadMusic(soundMusic);
	Mix_PlayMusic(gMusic, -1);
}