mypath=$(pwd)
cd ${mypath}/src
gcc *.c -lncurses -o main.exe
./main.exe "$1"
rm *.exe
cd ${mypath}
