SET mypath=%~dp0
call %mypath:~0,-1%/src/build_all.bat
call %mypath:~0,-1%/src/main.exe %1

