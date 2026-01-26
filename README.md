*This project has been created as part of the 42 curriculum by bgix, vgerthof*

**Description :**

	This project as for goal for us to make three sorting algorythm each with a different diifficulty.
	We have two stacks at our disposial, A and B, A being the stack that is required to be sorted at the end of the program.

	We can use multiple settings to define the program's behavour, each starting with a double minus (--).
		- bench -> Show all information about the process like difficuly, moves, disorder %.
		- simple -> Force the program to run the selected array in simple program.
		- medium -> Same as above with the complex sorting algorythm.
		- complex -> Same as above with the complex sorting algorythm.
		- adaptive -> Run the program with a algorythm program depending on the disorder percentage.

	Our sorting algorithm must sort a defined table under 2000 steps for 100 numbers and 12.000 steps for 500 numbers

		Steps are some functions that move, rotate or switch value in a stack

	In case of an error, Error must be displayed with a new line.
	Not using the bench settings must display every moves done in the terminala while running.
	Using the bench must not display the moves in the terminal while runing.
	Instead the bench must display the total moves of each type at the end of the program.

**Instructions :**

	Compiling using the Makefile, the command "make rng ARG=X" can be used, 
	it will automaticly create a list of disordered numbers, 
	the numbers can be changed in the ARG=X,, by default it is 100 but can be changed to what ever number that is above 0.

**Resources :**

	vgertoph, bgix -> Multiples video presenting multiple kind of algorythm.
	vgertoph -> Peer to Peer for algorythm recomandation.
	vgertoph, bgix -> Multiple websites presenting some algorythm (Geek4geek, Medium).
