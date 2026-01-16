# TODO:

- [ ] Create new c/bash program for viewing user input as raw morse and translated English

- [ ] More controls for input
- [ ] more LEDs for input feecback
- [ ] Buzzer feedback
- [ ] Use joystick module instead of buttons

- [ ] Write a description of the project in the README, and give some helpful repo info
- [ ] Credit online source for Makefile used in compiling, and flashing code
- [ ] Add drawing of my hardware setup
- [ ] Add video of hardware in action
- [ ] Create documentation for my Morse Code Data Bus design



# DONE:
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

# IDEAS
- Implement clock for signal length discernment instead of delays
- Implement some sort tree for morse to English translation ('.' = go left) ('-' = go right)

- Create a c/bash program that when you launch, flashes the software to the MCU and lets the user recieve incoming messages from the board.
- Later this program can allow the user to input English via his keyboard that is translated and displayed via LEDs on the bread board in morse. In this way we will acheive mutual direction communication.
