/*

    FileSystem.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

    DESCRIPTION:
    chickchirik game engine file system API
    that can manipulate file names and paths,
    open, close, read and write individual files,
    scan contents of a directory and handle
    asynchronious file I/O requests (future feature).
    Game engine uses SDL File I/O abstraction as
    its core. Moreover, FileSystem module is
    depended on some of the Boost C++ Libraries.
    This may change to custom libraties in the future.

*/

#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "StringID.hpp"
#include <SDL.h>
#include <SDL_image.h>
namespace bpt = boost::property_tree;


class FileSystem {
private:
    StringID        basePath;                               /*  engine base dir path                        */
    // StringID        prefPath;                               /*  hidden appdata dir path                     */
    bpt::ptree      pt;                                     /*  boost property tree to load and parse files */
    FileSystem();
public:
    static FileSystem& getInstance();                       /*  get singleton getInstance                   */
    int startUP();                                          /*  start up the subsystem                      */
    int shutDown();                                         /*  shut down the subsystem                     */
    bpt::ptree& parseJSON(const char* filename);            /*  load and parse JSON file                    */
    StringID& getBasePath();                                /*  get engine base dir path                    */
    // StringID getPrefPath();                                 /*  get hidden appdata dir path                 */
};
