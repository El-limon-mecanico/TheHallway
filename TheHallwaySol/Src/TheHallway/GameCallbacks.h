#include <memory>
class GameCallbacks{
private:
	static std::unique_ptr<GameCallbacks> instance_;
	void initCallbacks();
	static void ToEZGame();
	static void toMedGame();
	static void hardGame();
	static void fromMainMenuToControls();
	static void fromMainMenuToLvlSelector();
	static void fromControlsToMain();
	static void fromGameOverToLvlSelector();
	static void fromGameOverToMain();
public:
	GameCallbacks() {};
	~GameCallbacks() {};
	static bool Init();
	static GameCallbacks* Instance();
};