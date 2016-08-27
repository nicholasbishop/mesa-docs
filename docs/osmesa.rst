Off-screen Rendering
====================

Mesa's off-screen interface is used for rendering into user-allocated
memory without any sort of window system or operating system
dependencies. That is, the GL\_FRONT colorbuffer is actually a buffer in
main memory, rather than a window on your display.

The OSMesa API provides three basic functions for making off-screen
renderings: OSMesaCreateContext(), OSMesaMakeCurrent(), and
OSMesaDestroyContext(). See the Mesa/include/GL/osmesa.h header for more
information about the API functions.

The OSMesa interface may be used with any of three software renderers:

#. llvmpipe - this is the high-performance Gallium LLVM driver
#. softpipe - this it the reference Gallium software driver
#. swrast - this is the legacy Mesa software rasterizer

There are several examples of OSMesa in the mesa/demos repository.

.. rubric:: Building OSMesa
   :name: building-osmesa

Configure and build Mesa with something like:

::

    configure --enable-osmesa --disable-driglx-direct --disable-dri --with-gallium-drivers=swrast
    make

Make sure you have LLVM installed first if you want to use the llvmpipe
driver.

When the build is complete you should find:

::

    lib/libOSMesa.so  (swrast-based OSMesa)
    lib/gallium/libOSMsea.so  (gallium-based OSMesa)

Set your LD\_LIBRARY\_PATH to point to one directory or the other to
select the library you want to use.

When you link your application, link with -lOSMesa

.. raw:: html

   </div>