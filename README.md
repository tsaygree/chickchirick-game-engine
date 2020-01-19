# chickchirik game engine
chickchirik's proprietary video game engine

## Build Instructions

### Requirements

- [git](https://git-scm.com/)
- [cmake](https://cmake.org/)
- [gcc](https://www.gnu.org/software/gcc/) or [clang](https://clang.llvm.org/) or [msvc](https://visualstudio.microsoft.com/)
- [boost](https://www.boost.org)
- [sdl2](https://www.libsdl.org/index.php) and all sub-libraries

### Building

```bash
$ mkdir bin
$ mkdir build && cd build
$ cmake -G  *your generator*
$ -DCMAKE_BUILD_TYPE=Debug ../
$ make -j 2
$ make install
$ cd..
```

### Running
When in project's root directory run:
```bash
$ ./bin/tests
$ ./bin/core
```

### Links

- CMake: https://cmake.org/
- CMake documentation: https://cmake.org/documentation/
- CMake FAQ: https://gitlab.kitware.com/cmake/community/wikis/FAQ
