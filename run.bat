SET mypath=%~dp0
cd %mypath:~0,-1%/src
@REM call %mypath:~0,-1%/src/build_all.bat
@REM call %mypath:~0,-1%/src/main.exe %1 %2
call build_all.bat
call main.exe %1 %2
del *.o *.exe *.out
cd %mypath:~0,-1%
