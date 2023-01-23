#pragma once



class Resource
{

public:
	struct Images {

	};
	struct Audios {

	};

private:
	Images m_images;
	Audios m_audios;

public:
	static Resource* GetInstance();

	void Initalize();

	const Images& images() const { return m_images; }
	const Audios& audios() const { return m_audios; }

private:
	Resource() = default;
	~Resource() = default;
	Resource(const Resource&) = delete;
	const Resource& operator=(const Resource&) = delete;

	void LoadTexture();
	void LoadAudio();
};

