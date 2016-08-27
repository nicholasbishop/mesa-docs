Downloading
===========

Primary Mesa download site:
`ftp.freedesktop.org <ftp://ftp.freedesktop.org/pub/mesa/>`__ (FTP) or
`mesa.freedesktop.org <https://mesa.freedesktop.org/archive/>`__ (HTTP).

When a new release is coming, release candidates (betas) may be found
`here <ftp://ftp.freedesktop.org/pub/mesa/beta/>`__.

.. rubric:: Unpacking
   :name: unpacking

Mesa releases are available in three formats: .tar.bz2, .tar.gz, and
.zip

To unpack .tar.gz files:

::

        tar zxf MesaLib-x.y.z.tar.gz

or
::

        gzcat MesaLib-x.y.z.tar.gz | tar xf -

or
::

        gunzip MesaLib-x.y.z.tar.gz ; tar xf MesaLib-x.y.z.tar

To unpack .tar.bz2 files:

::

        bunzip2 -c MesaLib-x.y.z.tar.gz | tar xf -

To unpack .zip files:

::

        unzip MesaLib-x.y.z.zip

.. rubric:: Contents
   :name: contents

After unpacking you'll have these files and directories (among others):

::

    Makefile    - top-level Makefile for most systems
    configs/    - makefile parameter files for various systems
    include/    - GL header (include) files
    bin/        - shell scripts for making shared libraries, etc
    docs/       - documentation
    src/        - source code for libraries
    src/mesa    - sources for the main Mesa library and device drivers
    src/gallium     - sources for Gallium and Gallium drivers
    src/glx     - sources for building libGL with full GLX and DRI support

Proceed to the `compilation and installation
instructions <install.html>`__.

.. rubric:: Demos, GLUT, and GLU
   :name: demos-glut-and-glu

A package of SGI's GLU library is available
`here <ftp://ftp.freedesktop.org/pub/mesa/glu/>`__

A package of Mark Kilgard's GLUT library is available
`here <ftp://ftp.freedesktop.org/pub/mesa/glut/>`__

The Mesa demos collection is available
`here <ftp://ftp.freedesktop.org/pub/mesa/demos/>`__

In the past, GLUT, GLU and the Mesa demos were released in conjunction
with Mesa releases. But since GLUT, GLU and the demos change
infrequently, they were split off into their own git repositories:
`GLUT <http://cgit.freedesktop.org/mesa/glut/>`__,
`GLU <http://cgit.freedesktop.org/mesa/glu/>`__ and
`Demos <http://cgit.freedesktop.org/mesa/demos/>`__,

.. raw:: html

   </div>