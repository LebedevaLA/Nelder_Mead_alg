Как собрать и запустить(винда)<br>
Команды в терминале:<br>
mkdir build && cd build && cmake -Wno-dev-DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-Werror" -G "Unix Makefiles" ..<br>
make
