###############################################################
# Program:
#     Project, Moon Lander
#     Brother McCracken, CS165
# Author:
#     Mitchell Porter
# Summary:
#     Put your summary code here... 
# 	Moon Lander game.
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
# 
# I changed the flame from red to turqiose, I displayed "FUEL" 
# before the fuel number, I also added additional flavor text 
# to the success and failure texts below the normal text.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
lander.o: lander.cpp lander.h uiDraw.h
	g++ -c lander.cpp

# velocity.o: veloctity.cpp veloity.h
# 	g++ -c velocity.cpp

uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h uiDraw.h
	g++ -c ground.cpp

game.o:  game.cpp game.h uiDraw.h uiInteract.h point.h ground.h lander.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
# 
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
