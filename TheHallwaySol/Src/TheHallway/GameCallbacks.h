#include <memory>
class GameCallbacks{
private:
	static std::unique_ptr<GameCallbacks> instance_;
	void initCallbacks();
	static void fromMainMenuToGame();

	static void fromMainMenuToControls();
	static void fromControlsToMain();
public:
	GameCallbacks() {};
	~GameCallbacks() {};
	static bool Init();
	static GameCallbacks* Instance();
};