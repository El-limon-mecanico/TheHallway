# SUBMODULES

En este readme se encuentra la información necesaria para poder usar submodules en el proyecto actual.

## Organización

Este Proyecto consta de dos carpetas una que contendrá el juego y la otra (*Quack-Engine*) que contiene el motor y se trata de un submodulo.
La organización referente a los submodulos se encuentra en el archivo **.gitmodules**

## Instalación

La *instalacion viene hecha* en el momento que se descargá el repositorio sin embargo los archivos del submodulo no se actualizan ni se descargan solos es decir debemos actualizar por un lado el repositorio actual y por otro el submodulo o submodulos.

A día de hoy solo se han encontrado páginas con información de instalación desde consola si en el futuro se encuentra como realizarlo con GitHub Desktop por favor añadalo al documento.

### Desde consola

Tras una investigación se ha observado que se puede hacer en varios pasos o en 1 solo.
#### Varios pasos

**1º Paso** Lo primero que se debe hacer es inicializar los modulos para ello se usa el comando *git submodule init*

**2º Paso** Una vez se ha inicilizado se debe actualizar para ello se debe usar *git submodule update*

**3º Paso** Si los submodulos poseen submodulos a su vez se deben hacer los pasos 1 y 2 para cada submodulo.

#### 1 Solo paso

Si se prefiere realizar un único paso se puede realizar mediante el comando *git submodule update --init --recursive* 

### Desde Git Kraken

## Actualización
A día de hoy solo se han encontrado páginas con información de actualización desde consola o con GitKraken si en el futuro se encuentra como realizarlo con GitHub Desktop por favor añadalo al documento.

### Desde consola

Para actualizar se puede hacer ejecutando el siguiente comando *git pull --recurse-submodules'*

**Recomendacion**
Para no tener que realizar un pull y un update se recomiento ejecutar el siguiente comando ***git config --global alias.updateAll '!git pull && git submodule update --init --recursive && git pull --recurse-submodules'***
De tal forma que cuando se escriba el comando *git updateAll* realice un pull del proyecto principal y un pull de los submodulos


### Desde Git Kraken

https://support.gitkraken.com/working-with-repositories/submodules/#:~:text=To%20update%20submodules%2C%20navigate%20to,check%20out%20the%20referenced%20commit.