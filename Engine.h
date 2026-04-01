#pragma once

class UWorld;

class UEngine
{
protected:
	UEngine();

public:
	static int KeyCode;

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

	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(const FVector2D& InLocation, const char InMesh);
	void Flip();
	void TermBuffer();

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
};

#define GEngine		UEngine::GetInstance()