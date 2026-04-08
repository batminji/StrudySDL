#pragma once

class UWorld;
class UResourceManager;

class UEngine
{
protected:
	UEngine();

public:

	inline static UEngine* GetInstance()
	{
		static UEngine* Instance = new UEngine();
		return Instance;
	}

	inline UWorld* GetWorld() const
	{
		return World;
	}

	virtual ~UEngine();

	void Init();
	void Terminate();
	void Run();
	void Stop();

	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();

	void Render(const FVector2D& InLocation, const char InMesh);
	void Render(const FVector2D& InLocation, int R, int G, int B);
	void Render(const FVector2D& InLocation, SDL_Texture* InTexture, const FVector2D& InTextureLocation, const FVector2D& InTextureSize);
	void Render(const FVector2D& InLocation, SDL_Texture* InTextTexture, int InX, int InY);

	void Flip();
	void TermBuffer();

	inline const SDL_Event& GetEvent()
	{
		return Event;
	}

	inline const Uint8* GetState()
	{
		return State;
	}

	inline const float GetDeltaSeconds() const
	{
		return DeltaSeconds;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return Renderer;
	}

	inline SDL_Window* GetWindow() const
	{
		return Window;
	}

	inline UResourceManager* GetResourceManager() const
	{
		return ResourceManager;
	}

	inline TTF_Font* GetFont() const
	{
		return Font;
	}

	inline int GetMixOpenAudio() const
	{
		return MixOpenAudio;
	}
protected:
	void Input();
	void Tick();
	void Render();

protected:
	bool bIsRunning : 1;

	UWorld* World;
	int TileSize;

	SDL_Window* Window;
	SDL_Renderer* Renderer;

	TTF_Font* Font;

	SDL_Event Event;
	const Uint8* State;

	Uint32 LastTime;
	float DeltaSeconds;

	UResourceManager* ResourceManager;

	int MixOpenAudio = -1;
};

#define GEngine		UEngine::GetInstance()