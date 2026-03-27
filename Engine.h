#pragma once

class UWorld;

class UEngine
{
protected:
	UEngine();
	static UEngine* Instance;

public:
	static int KeyCode;

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}
		return Instance;
	}

	inline UWorld* GetWorld()
	{
		return World;
	}

	virtual ~UEngine();

	void Init();
	void Terminate();
	void Run();

protected:
	void Input();
	void Tick();
	void Render();

protected:
	bool bIsRunning : 1;

	UWorld* World;
};

#define GEngine		UEngine::GetInstance()