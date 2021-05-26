@echo off
cls
cd .\Quack-Engine\QuackEngineSol\

msbuild "QuackEngineSol.sln" /p:configuration=Debug
msbuild "QuackEngineSol.sln" /p:configuration=Release