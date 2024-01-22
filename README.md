# BlockBlasters-opengl-game
 
**Breakout Game Prototype**
Welcome to the Breakout Game Prototype repository! This project showcases a simple yet engaging breakout-style game developed using OpenGL. It demonstrates good software design principles and follows an object-oriented approach. Below, is the overview of the core classes used in this project:

**Classes Overview:**
**Game Class**
The Game class is the heart of the game, responsible for handling game states, logic, and rendering. It manages game updates and draws textures, ensuring a smooth gaming experience.

**GameLevel Class**
The GameLevel class is responsible for creating and managing game levels. It reads level data from external files and dynamically generates levels with bricks to be destroyed, providing a dynamic gaming environment.

**GameObject Class**
The GameObject class serves as a base class for all in-game objects. It defines common behaviors and component-style functionality, making it easier to create and manage game entities.

**ResourceManager Class**
The ResourceManager class takes care of loading shaders and textures, enabling the game to render objects correctly. It streamlines resource management, ensuring efficient resource usage.

**Shader Class**
The Shader class contains essential functions for creating vertex array objects and managing shaders, playing a vital role in the game's graphics rendering pipeline.

**SpriteRenderer Class**
The SpriteRenderer class handles the rendering of sprites and provides the basic logic for rendering textures on the game screen. It's responsible for creating the visual elements of the game.

**Texture Class**
The Texture class encapsulates the loading and management of textures used in the game, allowing for easy integration of images into the gameplay.

**Showcase**
![](https://github.com/architJanugade/BlockBlasters-opengl-game/blob/main/breakoutgif.gif)
