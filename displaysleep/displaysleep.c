//  
//  displaysleep.c
//  displaysleep
//
//  Created by Lars Mehrtens on 27.08.12.
//  Copyright (c) 2012 Lars Mehrtens. All rights reserved.
//
#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
/*
 * Immediately puts all attached displays to sleep. Use OS X's security settings
 * and set "Require password after sleep/screensaver" to immediately lock your
 * machine.
 */
int displaySleep(void) {
    io_registry_entry_t iore = IORegistryEntryFromPath(kIOMasterPortDefault,
            "IOService:/IOResources/IODisplayWrangler");

    if(!iore) return 1;

    int err = IORegistryEntrySetCFProperty(iore, CFSTR("IORequestIdle"),
            kCFBooleanTrue);
    IOObjectRelease(iore);

    return err;
}

int main(int argc, const char * argv[])
{
    return displaySleep();
}
