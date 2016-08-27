Compiling and Installing
========================

#. `Prerequisites for building <#prereq-general>`__

   -  `General prerequisites <#prereq-general>`__
   -  `For DRI and hardware acceleration <#prereq-dri>`__

#. `Building with autoconf (Linux/Unix/X11) <#autoconf>`__
#. `Building with SCons (Windows/Linux) <#scons>`__
#. `Building for other systems <#other>`__
#. `Library Information <#libs>`__
#. `Building OpenGL programs with pkg-config <#pkg-config>`__

.. rubric:: 1. Prerequisites for building
   :name: prereq-general

.. rubric:: 1.1 General
   :name: general

-  `Python <http://www.python.org/>`__ - Python is required. Version
   2.6.4 or later should work.
-  `Python Mako module <http://www.makotemplates.org/>`__ - Python Mako
   module is required. Version 0.3.4 or later should work.
-  `SCons <http://www.scons.org/>`__ is required for building on Windows
   and optional for Linux (it's an alternative to autoconf/automake.)
-  | lex / yacc - for building the GLSL compiler.
   | On Linux systems, flex and bison are used. Versions 2.5.35 and
     2.4.1, respectively, (or later) should work.
   | On Windows with MinGW, install flex and bison with:

   ::

       mingw-get install msys-flex msys-bison

   For MSVC on Windows, install `Win
   flex-bison <http://winflexbison.sourceforge.net/>`__.

-  For building on Windows, Microsoft Visual Studio 2013 or later is
   required.

.. rubric:: 1.2 For DRI and hardware acceleration
   :name: prereq-dri

The following are required for DRI-based hardware acceleration with
Mesa:

-  `dri2proto <http://xorg.freedesktop.org/releases/individual/proto/>`__
   version 2.6 or later
-  `libDRM <http://dri.freedesktop.org/libdrm/>`__ latest version
-  Xorg server version 1.5 or later
-  Linux 2.6.28 or later

If you're using a fedora distro the following command should install all
the needed dependencies:

::

      sudo yum install flex bison imake libtool xorg-x11-proto-devel libdrm-devel \
      gcc-c++ xorg-x11-server-devel libXi-devel libXmu-devel libXdamage-devel git \
      expat-devel llvm-devel python-mako

.. rubric:: 2. Building with autoconf (Linux/Unix/X11)
   :name: autoconf

The primary method to build Mesa on Unix systems is with autoconf.

The general approach is the standard:

::

      ./configure
      make
      sudo make install

But please read the `detailed autoconf instructions <autoconf.html>`__
for more details.

.. rubric:: 3. Building with SCons (Windows/Linux)
   :name: scons

To build Mesa with SCons on Linux or Windows do

::

        scons

The build output will be placed in
build/\ *platform*-*machine*-*debug*/..., where *platform* is for
example linux or windows, *machine* is x86 or x86\_64, optionally
followed by -debug for debug builds.

To build Mesa with SCons for Windows on Linux using the MinGW
crosscompiler toolchain do

::

        scons platform=windows toolchain=crossmingw machine=x86 libgl-gdi

This will create:

-  build/windows-x86-debug/gallium/targets/libgl-gdi/opengl32.dll — Mesa
   + Gallium + softpipe (or llvmpipe), binary compatible with Windows's
   opengl32.dll

Put them all in the same directory to test them.

.. rubric:: 4. Building for other systems
   :name: other

Documentation for other environments (some may be very out of date):

-  `README.VMS <README.VMS>`__ - VMS
-  `README.CYGWIN <README.CYGWIN>`__ - Cygwin
-  `README.WIN32 <README.WIN32>`__ - Win32

.. rubric:: 5. Library Information
   :name: libs

When compilation has finished, look in the top-level ``lib/`` (or
``lib64/``) directory. You'll see a set of library files similar to
this:

::

    lrwxrwxrwx    1 brian    users          10 Mar 26 07:53 libGL.so -> libGL.so.1*
    lrwxrwxrwx    1 brian    users          19 Mar 26 07:53 libGL.so.1 -> libGL.so.1.5.060100*
    -rwxr-xr-x    1 brian    users     3375861 Mar 26 07:53 libGL.so.1.5.060100*
    lrwxrwxrwx    1 brian    users          14 Mar 26 07:53 libOSMesa.so -> libOSMesa.so.6*
    lrwxrwxrwx    1 brian    users          23 Mar 26 07:53 libOSMesa.so.6 -> libOSMesa.so.6.1.060100*
    -rwxr-xr-x    1 brian    users       23871 Mar 26 07:53 libOSMesa.so.6.1.060100*

| **libGL** is the main OpenGL library (i.e. Mesa).
| **libOSMesa** is the OSMesa (Off-Screen) interface library.

If you built the DRI hardware drivers, you'll also see the DRI drivers:

::

    -rwxr-xr-x   1 brian users 16895413 Jul 21 12:11 i915_dri.so
    -rwxr-xr-x   1 brian users 16895413 Jul 21 12:11 i965_dri.so
    -rwxr-xr-x   1 brian users 11849858 Jul 21 12:12 r200_dri.so
    -rwxr-xr-x   1 brian users 11757388 Jul 21 12:12 radeon_dri.so

If you built with Gallium support, look in lib/gallium/ for
Gallium-based versions of libGL and device drivers.

.. rubric:: 6. Building OpenGL programs with pkg-config
   :name: pkg-config

Running ``make install`` will install package configuration files for
the pkg-config utility.

When compiling your OpenGL application you can use pkg-config to
determine the proper compiler and linker flags.

For example, compiling and linking a GLUT application can be done with:

::

       gcc `pkg-config --cflags --libs glut` mydemo.c -o mydemo

.. raw:: html

   </div>