displaysleep
============

Tiny OS X command line tool that puts all attached displays to sleep and turns
off keyboard illumination. This can be used to lock the computer: Use the setting
in Preferences->Security settings to specify how soon a password is required
after your computer's displays have been turned off. This is useful if e.g. you
take your MacBook to work regularly and need a "lock" feature like Windows' Meta+L.

Formerly, this functionality was provided on all Macs with optical drives because
these had an eject button on their keyboards. On laptops such as the Macbook Air
or the new Retina Macbook Pro however, the eject button is no longer available
and there is no way to call the shortcut manually or to assign it to a new
set of keys.

All this program does is issue a call to IOKit's registry, setting the corresponding
boolean value for "display sleep" to true.

UPDATE: As of spring 2013 this software is now obsolete. Apple has reassigned the
functionality from Shift+Ctrl+Eject to Shift+Ctrl+Power on all computers without
optical drive and a power key on their keyboards. However, you can still use it if
you'd like to assign a certain shortcut for some reason.

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
