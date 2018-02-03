# diff-pdf GUI
**diff-pdf GUI** is a simple launcher for **diff-pdf** (by [Václav Slavík](https://github.com/vslavik))

## Download binaries
Binaries for Windows can be found [here](https://github.com/smariel/diff-pdf_GUI/releases/latest).
It also includes the original diff-pdf binaries.

## Usage
- Double click `diff-pdf GUI.exe`
- Select two files to compare
- Select a destination file
- Optionaly, check the box to automaticly open the result file after comparison

![diff-pdf GUI Screenshot](http://www.otmax.fr/images/img/upload/big/1424612522.png)

## Compiling from sources
Since **diff-pdf GUI** is made with the Qt framework, it can be compiled for all supported platforms.
- Install Qt 5.4 or higher
- Download all **diff-pdf GUI** files
- Donwload [diff-pdf binary](http://vslavik.github.io/diff-pdf/) (or compil it) and place its folder at root
- Import the Qt project with QtCreator
- Build **debug** for developement and tests
- Build **release** then go to `/publish` folder and copy `/publish/diff-pdf` folder wherever you want.

Note that the release process use a `.cmd` to create the deployment version. You should remove the compiling step or rewrite the script for other platforms than Windows.
