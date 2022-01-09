# GL Cube
This is a virtual (3 x 3) Rubik's Cube application, allowing all the moves possible on a normal Rubik's cube, with the additional ability to solve itself. An existing solving library was used, specifically, the `rubiks-cube` package on PyPy. It is rendered using OpenGL and written mostly in C++. Currently, only Windows is supported (Viusal Studio), but a cross-platform version using CMake will be added soon.

## Requirements
- Visual Studio C++
- Docker

## Setup
1. `docker compose up -d` (runs the solver server)
2. Open the gl-cube.sln file, swicth to the x86 platform, and run the application.

## Controlling the Rubik's Cube
The cube's face can be individually rotated, and the whole cube itself can also be rotated. The direction of face turns are from a bird's-eye view perspective on the face. 

The front face is the rightmost face of the two faces facing outwards.

### Turning Faces
- `F`: Clockwise rotation of the front face
- `B`: Clockwise rotation of the back face
- `L`: Clockwise rotation of the left face
- `R`: Clockwise rotation of the right face
- `U`: Clockwise rotation of the top face
- `D`: Clockwise rotation of the bottom face
- `Left Shift` + one of the above commands produces a coressponding counterclockwise rotation. For example, `Left Shift + F` rotates the front face counterclockwise.

### Turning the Entire Cube
- `Left Arrow`: Turns the cube to the left
- `Right Arrow`: Turns the cube to the right
- `Up Arrow`: Turns the cube up
- `Down Arrow`: Turns the cube down
- `C`: Turns the cube clockwise along the positive z-axis
- `Left Shift + C`: Turns the cube counterclockwise along the positive z-axis

### Solving the Cube
Pressing `S` solves the cube.

Here's an animation of it solving one:
<br/>
![Solving Demo](demo/solving.gif)


## TODO
The following will be implemented in the future:
- Cross-platform compatibility using CMake
- Random shuffling
- Control of the rotation speed for user moves and solver moves
- An optimized solver using Thistlethwaite's algorithm



