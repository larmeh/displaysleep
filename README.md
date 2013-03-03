displaysleep
============

Tiny OS X command line tool that puts all attached displays to sleep and turns
off keyboard illumination. Eventually, this will lock the computer after a
certain amount of time, which can be set in the Preferences->Security settings.
This is useful if e.g. you take your MacBook to work regularly and need a "lock"
feature like Windows' Meta+L.
Formally, this functionality was provided on all Macs with optical drives and
eject button. On laptops such as the Macbook Air or the new Retina Macbook Pro
however, the eject button is no longer available and there is no way to
call the shortcut manually or to assign it to a new shortcut. This program is
merely a call to IOKit's corresponding registry entry, setting it to boolean
value true.

Installation
============

Make sure Apple's command line tools are installed.
Build manually using: 

    gcc -Wall -o displaysleep -framework IOKit \
         -framework Foundation displaysleep.c

Copy to e.g. /usr/local/bin and make sure the location is in your PATH.

If you use Jigish's excellent tool slate, put this in your .slate configuration
to assign a keyboard shortcut to displaysleep:
    
    bind l:cmd;alt shell wait path:~/bin '/Volumes/Daten/Users/larmeh/bin/displaysleep'

This would assign displaysleep to Cmd+Alt L. Use whatever suits you by altering
the first bind parameter.

TODO
====
- Makefile including 'install' target
- Manpage
