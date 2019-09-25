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
    StringID        basePath = SHID(__SOURCEPATH__);            /*  engine base dir path                        */
    // StringID        localPath;                                  /*  hidden appdata dir path                     */
    StringID        globalConfPath = SHID(__CONFIGPATH__);      /*  global engine configuration files folder    */
    StringID        assetsPath = SHID(__ASSETSPATH__);          /*  game assets path                            */
    bpt::ptree      pt;                                         /*  boost property tree to load and parse files */
    FileSystem();
public:
    static FileSystem& getInstance();                       /*  get singleton getInstance                   */
    uint32_t startUP();                                     /*  start up the subsystem                      */
    uint32_t shutDown();                                    /*  shut down the subsystem                     */
    const bpt::ptree& readJSON(const char* filename);      /*  load and parse JSON file                    */
    const StringID& getBasePath() const;                    /*  get engine base dir path                    */
    // const StringID& getLocalPath() const;                /*  get hidden appdata filepath                 */
    const StringID& getGlobalConfPath() const;              /*  get global config filepath                  */
    // const StringID& getLocalConfPath() const;            /*  get local config filepath                   */
};
