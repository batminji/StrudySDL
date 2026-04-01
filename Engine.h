#pragma once

class UWorld;

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

protected:
	void Input();
	void Tick();
	void Render();

protected:
	bool bIsRunning : 1;

	UWorld* World;

	SDL_Window* Window;
	SDL_Renderer* Renderer;
	SDL_Event Event;
	const Uint8* State;
};

#define GEngine		UEngine::GetInstance()