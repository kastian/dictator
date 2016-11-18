# Dictator

Remake of old BASIC game 'Dictator' for Spectrum, devised and written
by Don PRIESTLEY (DkTRONICS, 1983), rewritten in C by #kstn (2015).

There are no BASIC's surreallistic colours, but in other respects game
is quite identical. So if you like to tousle you nostalgia it is
written for you. ATM code is not very nice but works quite well.

Any feedback, ideas, fixes, bug reports are welcomed.

------------------------------------------------------------------------

##INSTALLATION:

Clone the repository

`$ git clone https://github.com/kastian/dictator.git`

Make

`$ make`

For successful making you need "ncurses.h" so may be you'll need
install it.

And run

`./dictator`

Or install it

`$ sudo make install`


Game consists only of one executable file so if you'll want to
uninstall it you can use

`$ sudo make uninstall`

or just remove file

`$ sudo rm $(which dictator)`
