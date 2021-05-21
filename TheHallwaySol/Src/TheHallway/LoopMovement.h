#include "Component.h"
#include <vector>
#include "Vector3D.h"
class Rigidbody;
class LoopMovement : public Component {
protected:

private:
	float playerTriggerDistance_ = 15;
	Transform* playerTr_ = nullptr;
	//Puntero al rigidbody
	Rigidbody* rb_ = nullptr;
	//velocidad a la que se mueve
	float speed_;
	//vector con los posibles objetivos
	std::vector<Vector3D> objectives_;
	//posicion del array en el que se encuentra el objetivo actual
	int actualObjective_;
	/// actualiza el objetivo
	void updateObjective();
	//Ctualiza el valor de velocity
	void updateVelocity();
public:
	///Constructor por defecto y con argumentos
	LoopMovement(float speed=0,std::vector<Vector3D>objectives=std::vector<Vector3D>(),int next=0):speed_(speed),objectives_(objectives),actualObjective_(next) {}
	///Destructor por defecto
	~LoopMovement() {}
	///Posibilita leer la componente desde lua
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	//Pone al objeto mirando al lugar adecuado y setea la gravedad a 0
	void start() override;
	//LLama a los metodos move y updateObjective
	void update() override;
	//devuelve el nombre de la componente
	static std::string GetName() { return "LoopMovement"; }

	virtual void onEnable();
	virtual void onDisable();
};