 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Text-Based Role Playing Game
 
 > Authors: Nikhil Narasimhan(https://github.com/nikhilmn7), Paolo Uytiepo(https://github.com/dosanpao), Laith Omar(https://github.com/LaithOmar04), Steven Gonzalez (https://github.com/MuffinManss)

## Project Description
Why this Project is Interesting to Us

* The project is interesting to us because we have all played and enjoyed online games, so we feel that it would be interesting to create our own.

Languages/Tools/Technologies

* C++, Git, Cmake, Visual Studio Code

Input/Output

Input from the User: 
* Keys will be used to input character information like Name, Age, Gender, and Species. 
* Number keys will be used to input choices for different actions 
    * (e.g. run, attack, defend).
* Number keys will be used to choose from different moves 
    * (e.g. after choosing to attack or run ect).
* Keys will be used after certain story messages are outputted in order to continue the game 
    * (e.g. "press any key to continue").

Output: 
* Your customized character with specified name, age, and species.
* Character attributes will be ouputted after each turn during combat 
    * (e.g. health, attack, defense, XP).
* During battle, a list of possible actions will be outputted for the user to choose from 
    * (e.g. run, attack, inventory).
* Messages will be outputted when the user encounters an enemy.
* The results of a battle will be ouputted depending on whether the user wins or loses.

Features

* The game will feature a story following the main character as they go on a path to defeat the big boss.
* As the story progresses, the mc finds themselves in battles against smaller foes and, occasionally, mini-bosses.
* The battles againt these foes will increase in difficulty as the mc continues on their journey.
* In between boss fights, there will be "random battle modes" where you can fight lower level opponents
    * These battles will help the mc gain experience and rewards.
* The game will feature an experience system, where the mc gains XP in order to increase their own level.
    * Increasing a player's level will lead to buffs such as increased health and attack.
* A turn-based battle system will be featured, where the user picks from several options during their turn in a fight.
    * These options will include actions like running away, defending, or attacking.
* The game will be displayed through text based options.

 
## User Interface Specification

### Navigation Diagram

[https://drive.google.com/file/d/1ZZGJPSmTCBtNbqh8Th8uPnrlw9e59aU9/view?usp=sharing
](https://drive.google.com/file/d/1lj1SzoKqkfbhp4SFGpH6L0s7CCyA6CnZ/view?usp=sharing)

### Screen Layouts
Screen layouts with example inputs and outputs:

Start screen:
* This screen is outputted at the very start of the game. Here, the user is prompted to input information about their desired character, including their name, gender, age, and species

> Please enter the name of your character
> 
> Gon
> 
> What gender is your character? Enter 1 for male or 2 for female
> 
> 1
> 
> How old is your character?
> 
> 13
> 
> Finally, what species is your character? Please choose from the following options:
> 
> 1. Angel   2. Demon   3. Dragon   4. Wizard
> 
> 4
> 
> Welcome, Gon! Your journey begins now


Stats screen:
* This screen is output after important events in the game, and it gives the current stats of the user’s character. These events include when the user first chooses their species, when the character levels up, and after the character defeats an enemy. A screen similar to this is output after every enemy turn in battle, but the “level” and “experience” lines are omitted.

> Current Stats:
> 
> LEVEL: 0
> 
> EXPERIENCE: 0
>
> HEALTH: 100
>
> ATTACK: 20
>
> DEFENSE: 15


Battle Options Screen:
* This screen is output before every one of the user’s turns in battle. The user is given an option on how they want to move forward in the battle.

> The enemy facing you is waiting for your next move. What will you do? Please choose from the following:
> 
> 1. Run   2. Fight   3. Open Inventory
>
> 1
>
> You failed to run away!


Fight Screen:
* This screen is shown when the user decides to fight in a battle. A list of possible moves is given for the user to choose.
> What move would you like to use? 
>
> 1. Fireball   2. Poison Dagger   3. Melee Attack
>
> Enter the number for the move you would like to use, or enter 0 to return
>
> 1
>
> You dealt 20 damage!

Inventory screen:
* This screen is shown when the user decides to open their inventory during their turn in battle.
> You are currently holding the following items:
>
> 1. Heal Potion   2. XP Boost   3. Attack Potion
>
> Enter the number for the item you would like to use, or enter 0 to exit your inventory
> 
> 3
>
> Your attack stat has temporarily gone up by 20!

Story screen:
* This screen is shown during key moments in the progression of the games’ story (e.g the game’s start, defeating a boss, etc.). A message is shown depending on what happens in the story, and the user is prompted to continue. An example is shown:

> Congratulations, you have defeated the mini-boss, Neferpitou! The local townsfolk are eternally grateful to you for saving their village, and they wish you luck on your journey. You now set your sights on defeating the next boss.
>
> Enter any key to continue…




## Class Diagram

https://drive.google.com/file/d/1j73y57attEoYU9flNmkEU-CSAtRRcJcn/view?usp=sharing

## UML Diagram Updates

1) We decided to add derived classes for the Character and Enemy classes to adhere to the Open Closed Principle, since we have 4 types of characters and 3 types of enemies. Originally, we had the Character class initialize each type of character by just changing their attribute values, but we realized that we would have to change and add more functions if we wanted to add another character type later on. The same goes for the enemy class, where if we wanted to add more enemies later on, it would be easier to extend the enemy class rather than change/add functions within the enemy class. This helped us write better code because we can easily extend these classes if needed, and it is much more readable/understandable to instantiate our characters and enemies through subclasses.
2) We also added derived classes for the Item class to adhere to the Open Closed Principle. Since we currently have 3 different types of items (health, attack, and defense), we wanted to separate them instead of initializing them through the Item base class directly. We want the Item class to be closed for modification but open for extension, so it will be much easier to add more item types later on. This helped us write better code since we can easily extend the item class if needed, and it is much more readable and understandable to instantiate our items through subclasses.
3) Finally, we added a Reward System class to manage how players acquire items during the game. Originally, we were going to display the available items in our Game class or Battle System class, but we realized that this violated the Single Responsibility Principle. By creating a Reward System class, we can adhere to SRP by making a class for the purpose of managing and displaying the acquisition of items for a player, rather than putting this functionality in the Game class directly. We are able to write better code now because we can separate the responsibilites of different classes to avoid clutter.


 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
cmake .
make
./MainExecutable
 ## Testing
We used unit testing to test and validate our project. We made sure to test every function within each class to ensure proper functionality, providing necessary in-game inputs to validate each function. We also ran our game through a large number of different scenarios to ensure that the different aspects and features of the game were correctly implemented.
 
