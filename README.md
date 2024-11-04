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
    * (e.g. after choosing to attack, the player can choose from a list of moves to use).
* Keys will be used after certain story messages are outputted in order to continue the game 
    * (e.g. "press any key to continue").

Output: 
* Your customized character with specified name, age, and species.
* Character attributes will be ouputted after each turn during combat 
    * (e.g. health, attack, defense, speed, XP bar).
* During battle, a list of possible actions will be outputted for the user to choose from 
    * (e.g. run, attack, defend, various moves).
* Messages will be outputted when the user encounters an enemy.
* The results of a battle will be ouputted depending on whether the user wins or loses.

Features

* The game will feature a story following the main character as they go on a path to defeat the big boss.
* As the story progresses, the mc finds themselves in battles against smaller foes and, occasionally, mini-bosses.
* The battles againt these foes will increase in difficulty as the mc continues on their journey.
    * The increasing difficulty will be marked by the opponent's level, continuing until you reach the Big Boss and beat the game.
* In between boss fights, there will be "random battle modes" where you can fight lower level opponents
    * These battles will help the mc gain experience and rewards.
* The game will feature rewards for the player after certain requirements are met.
    * For example, the player can recieve a reward after defeating a mini-boss or reaching a certain level.
    * The rewards given can range from extra XP to new moves and weapons.
* The game will feature an experience system, where the mc gains XP in order to increase their own level.
    * Increasing a player's level will lead to buffs such as increased health and attack.
* A turn-based battle system will be featured, where the user picks from several options during their turn in a fight.
    * These options will include actions like running away, defending, or attacking with their weapon of choice.
* Though the game is text-based, we also may potentially create a UI for the game.

 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Each team member needs to submit the Individual Contributions Form on Canvas for this phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase  II, and a description of their contributions. Remember that each team member should submit the form individually.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram

https://drive.google.com/file/d/1aysvTaWajvOlio9Uh1EDi-s6d8EbrmNm/view?usp=sharing
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
