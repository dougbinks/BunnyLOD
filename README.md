Original code: https://github.com/melax/sandbox/tree/master/bunnylod

More information & article link: http://www.melax.com/polychop

	Polygon Reduction Demo
	By Stan Melax (c) 1998
	http://www.melax.com

Mouse dragging spins the rabbit.

August 2014: code style upgraded to be more consistent with graphics/gamdev conventions 

MIT Licensed as per https://github.com/melax/sandbox/blob/master/LICENSE

# BunnyLOD Cross Platform Port
May 2020: Cross platform port using GLFW and CMake by Doug Binks

I have made sufficient and minimal changes to Stan Melax's code to get it running with GLFW on Windows, OSX and Linux.

The main interesting code is in [progmesh.h](https://github.com/dougbinks/BunnyLOD/blob/master/progmesh.h) and [progmesh.cpp](https://github.com/dougbinks/BunnyLOD/blob/master/progmesh.cpp).

The code requires a C++14 compatible compiler. Visual Studio on Windows, Clang on OSX and GCC on Linux tested.

![BunnyLOD screenshot](https://github.com/dougbinks/images/blob/master/BunnyLOD.jpg?raw=true)

## Getting the code

The easiest way to get hold of the starter code is to run the following command using a shell you can run git from:

```
git clone --recursive https://github.com/dougbinks/BunnyLOD
```

If you are on Windows you can download git from [git-scm.com/download/win](https://git-scm.com/download/win) and use the right click menu in Windows File Explorer to "Git Bash here" and then run git commands.

This will create the directory _GLFW-CMake-starter_ and get the latest source code, using the ```--recursive``` option to download the GLFW code which is included in the repository as a submodule. If you want to run further git commands from the command line you'll need to cd into the directory:

```
cd BunnyLOD
```

Alternatively you can use a git GUI program such as [Fork](https://git-fork.com/) to get the code. Most of these will automatically download the git submodules.

If you download the code from GitHub via the "Download ZIP" approach, you'll also need to download GLFW into the _glfw_ folder. The correct version can be found by clicking on the _glfw_ folder you see on the [front page of the _BunnyLOD_ GitHub repository](https://github.com/dougbinks/BunnyLOD).

## Using CMake to create the project

From a command prompt in the `BunnyLOD` directory:
1. `mkdir build`
1. `cd build`
1. `cmake ..`
1. Either run `make all` or for Visual Studio open `BunnyLOD.sln`

## Also see

[BGFX](https://github.com/bkaradzic/bgfx) example 42-bunnlod by [cloudwu](https://github.com/cloudwu):
https://bkaradzic.github.io/bgfx/examples.html#bunnylod
![BGFX example 42-bunnlod screenshot](https://github.com/bkaradzic/bgfx/raw/master/examples/42-bunnylod/screenshot.png)

This port to render with the [BGFX GFX API](https://github.com/bkaradzic/bgfx) also adds a [Dear ImGui UI](https://github.com/ocornut/imgui) and the code is converted to C.

