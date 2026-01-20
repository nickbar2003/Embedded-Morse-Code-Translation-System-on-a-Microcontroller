# TODO:
- [ ] Better controls
- [ ] Watch this guys video on timers and interupts: https://www.youtube.com/watch?v=JRUSXtnjcNg&list=PLA6BB228B08B03EDD&index=2 

- [ ] Maybe convert from delays to timers

- [ ] Comment Code


- [ ] more LEDs for input feecback
- [ ] Buzzer feedback - In Progress
- [ ] Use joystick module instead of buttons
- [ ] Display output on either LCD or LED screen

- [ ] Write a description of the project in the README, and give some helpful repo info
- [ ] Credit online source for Makefile used in compiling, and flashing code
- [ ] Create documentation for my Morse Code Data Bus design



# DONE:
- [x] Before pushing new code, make Mark I release
- [x] Create new c/bash program for viewing user input as raw morse and translated English
- [x] Link Mark I video to repo somehow
- [x] Store seperate signals together as program variables
- [x] Correctly associate multiple morse singals with a single english letter
- [x] Signal -> Morse -> English -> Serial
- [x] Figured out how to mointor serial port over wsl
- [x] Discern signal lengths
- [x] Establish Serial communication from MCU -> my PC
- [x] Study USART protocol 
- [x] Refactor USART codeto work my own way, to prove to myself that I now have this skill.
- [x] Organize Code
- [x] Link documentation
- [x] Add drawing of my hardware setup
- [x] Add video of hardware in action

# IDEAS
- Implement clock for signal length discernment instead of delays
- Implement some sort tree for morse to English translation ('.' = go left) ('-' = go right)

- Create a c/bash program that when you launch, flashes the software to the MCU and lets the user recieve incoming messages from the board.
- Later this program can allow the user to input English via his keyboard that is translated and displayed via LEDs on the bread board in morse. In this way we will acheive mutual direction communication.
- https://app.cirkitdesigner.com/project
