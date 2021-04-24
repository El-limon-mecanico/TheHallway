# Del Motor se obtienen 
- Render
- Transform
- Rigidbody
- Collider
- Trigger
- Light
- Camera
## Componentes de la entidad Player

- PlayerMovement será la encargada de mover al jugador medianre WASD (si se pulsa Shift empieza a correr esto podria ser hecho en otra componente)

- CameraMovement mediante el movimiento del ratón rotará la cámara

- Lighter es la componente encargada de gestionar la linterna, debe ir descargandose de manera constante mientras este encendida y deberá poder recargarse.

- PlayerSound se encargara de gestionar los sonidos que realiza y que escucha el jugador

- Health es la encargada de gestionar las vidas del jugador

## Comun entre los enemigos

- EnemyState Se encarga de gestionar el estado del enemigo (Patrolling, Following)

- VisionRange  Determina si el jugador se encuentra a la distancia suficiente y en la direccion correcta como para que el enemigo pueda verlo

- SoundEmit Se encarga de gestionar el sonido que producen los enemigos

- FollowPlayer El enemigo debe estar en estado Following para usar esta componente se trata de una componente que hace que el enemigo siga al player

### Sadico  y Rastreator

- RandomMovement Se mueven aleatoriamente hasta cierta condicion

- SoundListener Se encargara de gestionar los sonidos que recibe 

### Sadico

Usará el estado para saber que movimiento usar y si le estan viendo no se mueve

### Rastreator (guau guau)

Usará el estado para saber que movimiento usar 

### Protector

- GuardianMovement Patron de movimiento protegiendo la palanca
