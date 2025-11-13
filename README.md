# Hackton Smart Chain

## Overview
The Hackton Smart Chain project is designed to implement a smart LED control system using various classes and states to manage the behavior of LEDs and buttons. The project is structured to separate class definitions and implementations, making it easier to maintain and extend.

## Project Structure
```
hackton-smart-chain
├── include
│   ├── Led.h
│   ├── RgbLed.h
│   ├── Button.h
│   ├── RelationStateFacade.h
│   ├── RelationMatchContext.h
│   └── states
│       ├── IMatchState.h
│       ├── SetupState.h
│       └── ReadyState.h
├── src
│   ├── main.cpp
│   ├── Led.cpp
│   ├── RgbLed.cpp
│   ├── Button.cpp
│   ├── RelationStateFacade.cpp
│   ├── RelationMatchContext.cpp
│   └── states
│       ├── SetupState.cpp
│       └── ReadyState.cpp
├── test
│   └── unit
│       └── test_main.cpp
├── platformio.ini
└── README.md
```

## Classes and Interfaces
- **Led**: Represents a basic LED with methods to turn it on and off.
- **RgbLed**: Inherits from `Led` and adds functionality to set the color using RGB values.
- **Button**: Represents a button with functionality to check if it has been pressed.
- **RelationStateFacade**: Manages the interaction between the RGB LED and the button.
- **RelationMatchContext**: Handles the current state of the system and manages LED states.
- **IMatchState**: An interface for different match states.
- **SetupState**: A state that prepares the system for operation.
- **ReadyState**: A state indicating that the system is ready for interaction.

## Build and Test
To build and test the project, use PlatformIO. Ensure that all dependencies are correctly specified in the `platformio.ini` file.

## Contribution
Feel free to contribute to the project by adding new features or improving existing functionality. Please follow the project's coding standards and guidelines.