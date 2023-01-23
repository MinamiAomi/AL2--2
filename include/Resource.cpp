#include "Resource.h"

Resource* Resource::GetInstance() {
	static Resource instance;
	return &instance;
}

void Resource::Initalize()
{
	LoadTexture();
	LoadAudio();
}

void Resource::LoadTexture()
{
}

void Resource::LoadAudio()
{
}
