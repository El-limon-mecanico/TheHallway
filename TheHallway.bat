@echo off

:: Compilamos el motor
cd .\TheHallwaySol\Quack-Engine
call QuackEngine.bat


:: Compilamos la solucion en debug y release
cd ..\..
msbuild "TheHallwaySol.sln" /p:configuration=Debug
msbuild "TheHallwaySol.sln" /p:configuration=Release

pause