# dwm version
VERSION = 6.2

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

#X11INC = /usr/X11R6/include
#X11LIB = /usr/X11R6/lib
X11INC = ${PREFIX}/include
X11LIB = ${PREFIX}/lib

# Xinerama, comment if you don't want it
XINERAMALIBS  = -l Xinerama
XINERAMAFLAGS = -D XINERAMA

# freetype
FREETYPELIBS = -l fontconfig -l Xft
FREETYPEINC = /usr/include/freetype2
# OpenBSD (uncomment)
FREETYPEINC = ${X11INC}/freetype2

# includes and libs
INCS = -I ${X11INC} -I ${FREETYPEINC}
LIBS = -L ${X11LIB} -l X11 ${XINERAMALIBS} ${FREETYPELIBS}

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
#CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# Solaris
#CFLAGS = -fast ${INCS} -D VERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = cc
