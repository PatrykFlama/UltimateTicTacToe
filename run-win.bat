SET mypath=%~dp0
cd %mypath:~0,-1%/src
gcc *.c -o main.exe
call main.exe %1 %2
del *.o *.exe *.out
cd %mypath:~0,-1%
