cd "$(dirname "$0")/Third_Party/Premake/"

#if [["$OSTYPE" == "msys"]]; then
./premake5.exe --file=./Infinity_Engine.lua vs2019
#elif [[ "$OSTYPE" == "linux-gnu" ]]; then
  #Path to linux premake executable
#fi
