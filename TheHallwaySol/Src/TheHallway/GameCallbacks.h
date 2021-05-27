#include <memory>
class GameCallbacks{
private:
	static std::unique_ptr<GameCallbacks> instance_;
	void initCallbacks();
	static void ToEZGame();
	static void toMedGame();
	static void hardGame();
	static void toControls();
	static void back();
	static void toLvlSelector();
	static void toMenuPpl();
	static void fullscreen();
	static void quit();
	static void toQuitScene();
public:
	GameCallbacks() {};
	~GameCallbacks() {};
	static bool Init();
	static GameCallbacks* Instance();
};