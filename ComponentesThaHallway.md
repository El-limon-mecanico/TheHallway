# Del Motor se obtienen 
- Render
- Transform

## Componentes de la entidad Player

- PlayerMovement será la encargada de mover al jugador medianre WASD (si se pulsa Shift empieza a correr esto podria ser hecho en otra componente)

- CameraMovement mediante el movimiento del ratón rotará la cámara

- Lighter es la componente encargada de gestionar la linterna, debe ir descargandose de manera constante mientras este encendida y deberá poder recargarse.

- PlayerSound se encargara de gestionar los sonidos que realiza y que escucha el jugador

- Health es la encargada de gestionar las vidas del jugador asi como de renderizar la UI

## Comun entre los enemigos

- EnemyState Se encarga de gestionar el estado del enemigo (Patrolling, Following)

- VisionRange  Determina si el jugador se encuentra a la distancia suficiente y en la direccion correcta como para que el enemigo pueda verlo

- SoundEmit Se encarga de gestionar el sonido que producen los enemigos

- FollowPlayer El enemigo debe estar en estado Following para usar esta componente se trata de una componente que hace que el enemigo siga al player

### Sadico de Carglass

- SadicMovement Se encarga de mover este enemigo y de pararlo si esta mirando hacia el jugador

- SoundListener Se encargara de gestionar los sonidos que recibe 

### Rastreator (guau guau)

- RastreatorMovement(¿Quizás podría ser como SadicMovement?)

### Protector

En principio no se cree que requiera más que las comunes
