--------------------------------------- Project - Save The King -----------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Students and IDs -------------------------------------------- 
-------- Samah Rajabi (student number: 211558556) & Saja Abu Maizar (student number: 208072371) ---------
---------------------------------------------------------------------------------------------------------
----------------------------------------  General Description  ------------------------------------------
---------------------------------------------------------------------------------------------------------
About the game:
In the game, the player must bring the king to his throne -chair-.
The problem is that the king is limited in his abilities and can only move on empty tiles on the board.
Thus, The king is accompanied by his entourage that will clear the way for him and help him reach his
goal.
There are four characters that the player has control over:
 ● The King: he can walk on empty tiles, or keys tiles (but he can't take them),
   he can also travel through teleport cells. Lastly, he can sit on the throne.
 ● The Mage: his special ability is to put out fire (by walking over fire tiles).
   He can walk on empty tiles, fire tiles, and key tiles.
   Finally, he can stand on teleport cells but can't travel through them.
 ● The Warrior: his special ability is to fight the orcs (by walking over orcs tiles).
   He can walk on empty tiles, orcs tiles and keys tiles. He can also use teleport cells.
 ● The Thief: his special ability is to take a key (keys appear on the board whenever the warrior
   kills an orc) and open a gate with it. Finally, He can use teleport cells.
   Note that the thief can carry only one key at a time.
The player wins the level when the king reaches his throne.
** to be continued:**
**gifts, enemy, how to change the curr character, how to move**
---------------------------------------------------------------------------------------------------------
------------------------------------------------- Design ------------------------------------------------
---------------------------------------------------------------------------------------------------------
the main starts the game by creating a Controller object.
the Controller creates a HomePage object, then in a while loop the controller handles the moves and
clickes on the window of the HomePage:
 ● when the user clickes the "help" button in HomePage, the controller creates a Help object that opens
   a Help window and present info about the characters and how to play the game.
 ● when the user clickes the "exit" button in HomePage, the controller exits the program.
 ● when the user clickes the "start" button in HomePage, the controller closes the window of HomePage
   and creates a Level object.
In a for loop, the Level object starts new levels (NUM_OF_LEVEL times). For each level, it reads
a text file to calculate the size of the board and whether or not the level istime-limited.
Lastly, it creates a Board object that creates the map (board) of the level.
a Board object reads the map of the level from a text file, saves it in a vector[of vectors]
and finally prints the map [and more info? timer, levelData]to the window of the level.
**to be continued: types of GameObjects**
---------------------------------------------------------------------------------------------------------
** additional notes: how to add a new level, what to write to the text file of the level. **
