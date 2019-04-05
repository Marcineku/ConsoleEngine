# ConsoleEngine


# Description
ConsoleEngine is a project made purely for fun, inspired by javidx9 and his olcConsoleGameEngine.
It supposed to be a thin layer on top of a windows api for windows 10 console.
It provides basic input and drawing support, also currently has Vector2, Rect and Timer classes implemented.
All engine components are under "ce" namespace.

# How to use
To use it, download this project, build it in Visual Studio, provide ConsoleEngine.h, ConsoleEngine.lib and ConsoleEngine.dll
for your game project, then make your main game class to inherit after ce::Engine and pass console, font, and app name data
to its constructor.
After that just overwrite "update" function and you are good to go.

# Demo-app footage
https://youtu.be/f4eD30wTzZc

# Important
ConsoleEngine is built as a .dll file.
To run demo-app of a ConsoleEngine, go to project properties, set Configuration to "All Configurations" and Platform to "All Platforms".
Then go to General -> Project Default and set Configuration Type to "Application (.exe)". Then just simply choose either Debug 
or Release mode and click Local Windows Debugger to run it.

# Controls
### WSAD/Arrow keys - to move a box around
### Hold LMB        - to create a rectangle
