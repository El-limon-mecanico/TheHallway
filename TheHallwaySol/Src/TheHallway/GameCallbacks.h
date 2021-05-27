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
public:
	GameCallbacks() {};
	~GameCallbacks() {};
	static bool Init();
	static GameCallbacks* Instance();
};