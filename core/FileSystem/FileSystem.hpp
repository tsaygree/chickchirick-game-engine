/*

    FileSystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

    DESCRIPTION:
    chickchirik game engine file system API
    that can manipulate file names and paths,
    open, close, read and write individual files,
    scan contents of a directory and handle
    asynchronious file I/O requests.
    Game engine uses SDL File I/O abstraction as
    its core. Moreover, FileSystem module is
    depended on some of the Boost C++ Libraries.
    This may change to custom libraties in the future.

*/

#pragma once

class FileSystem {
private:
    FileSystem();
public:
    static FileSystem& getInstance();
    int startUP();
    int shutDown();
};
