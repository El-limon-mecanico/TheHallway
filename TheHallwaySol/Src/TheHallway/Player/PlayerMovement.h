#include "Component.h"
class Transform;

class PlayerMovement: public Component{
protected:

private:
float speed_;
Transform* tr_;
public:
PlayerMovement(){}
~PlayerMovement(){}
void init();
void move();
void update() override;
}