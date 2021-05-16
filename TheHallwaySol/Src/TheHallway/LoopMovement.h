#include "Component.h"
#include <vector>
#include "Vector3D.h"
class LoopMovement : public Component {
protected:

private:
	//velocidad a la que se mueve
	float speed_;
	//vector con los posibles objetivos
	std::vector<Vector3D> objectives_;
	//posicion del array en el que se encuentra el objetivo actual
	int actualObjective_;
	/// actualiza el objetivo
	void updateObjective();
public:
	///Constructor por defecto y con argumentos
	LoopMovement(float speed=0,std::vector<Vector3D>objectives=std::vector<Vector3D>(),int next=0):speed_(speed),objectives_(objectives),actualObjective_(next) {}
	///Destructor por defecto
	~LoopMovement() {}
	///Posibilita leer la componente desde lua
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	///Mueve el objeto en posiciones globales hacia el siguiente objetivo
	void move();
	//LLama a los metodos move y updateObjective
	void update() override;
	//devuelve el nombre de la componente
	static std::string GetName() { return "LoopMovement"; }
};