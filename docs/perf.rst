Performance Tips
================

Performance tips for software rendering:

#. Turn off smooth shading when you don't need it (glShadeModel)
#. Turn off depth buffering when you don't need it.
#. Turn off dithering when not needed.
#. Use double buffering as it's often faster than single buffering
#. Compile in the X Shared Memory extension option if it's supported on
   your system by adding -DSHM to CFLAGS and -lXext to XLIBS for your
   system in the Make-config file.
#. Recompile Mesa with more optimization if possible.
#. Try to maximize the amount of drawing done between glBegin/glEnd
   pairs.
#. Use the MESA\_BACK\_BUFFER variable to find best performance in
   double buffered mode. (X users only)
#. Optimized polygon rasterizers are employed when: rendering into back
   buffer which is an XImage RGB mode, not grayscale, not monochrome
   depth buffering is GL\_LESS, or disabled flat or smooth shading
   dithered or non-dithered no other rasterization operations enabled
   (blending, stencil, etc)
#. Optimized line drawing is employed when: rendering into back buffer
   which is an XImage RGB mode, not grayscale, not monochrome depth
   buffering is GL\_LESS or disabled flat shading dithered or
   non-dithered no other rasterization operations enabled (blending,
   stencil, etc)
#. Textured polygons are fastest when: using a 3-component (RGB), 2-D
   texture minification and magnification filters are GL\_NEAREST
   texture coordinate wrap modes for S and T are GL\_REPEAT GL\_DECAL
   environment mode glHint( GL\_PERSPECTIVE\_CORRECTION\_HINT,
   GL\_FASTEST ) depth buffering is GL\_LESS or disabled
#. Lighting is fastest when: Two-sided lighting is disabled
   GL\_LIGHT\_MODEL\_LOCAL\_VIEWER is false GL\_COLOR\_MATERIAL is
   disabled No spot lights are used (all GL\_SPOT\_CUTOFFs are 180.0) No
   local lights are used (all position W's are 0.0) All material and
   light coefficients are >= zero
#. XFree86 users: if you want to use 24-bit color try starting your X
   server in 32-bit per pixel mode for better performance. That is,
   start your X server with startx -- -bpp 32 instead of startx -- -bpp
   24
#. Try disabling dithering with the MESA\_NO\_DITHER environment
   variable. If this env var is defined Mesa will disable dithering and
   the command glEnable(GL\_DITHER) will be ignored.

.. raw:: html

   </div>