#include "Component.h"
class Transform;

class Lighter: public Component{
protected:

private:
float actualCharge_;
Transform* tr_;
public:
Lighter(){}
~Lighter(){}
void init();
void charge();
void update() override;
}