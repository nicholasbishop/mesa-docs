Mesa EGL
========

The current version of EGL in Mesa implements EGL 1.4. More information
about EGL can be found at http://www.khronos.org/egl/.

The Mesa's implementation of EGL uses a driver architecture. The main
library (``libEGL``) is window system neutral. It provides the EGL API
entry points and helper functions for use by the drivers. Drivers are
dynamically loaded by the main library and most of the EGL API calls are
directly dispatched to the drivers.

The driver in use decides the window system to support.

.. rubric:: Build EGL
   :name: build-egl

#. Run ``configure`` with the desired client APIs and enable the driver
   for your hardware. For example

   ::

         $ ./configure --enable-gles1 --enable-gles2 \
                       --with-dri-drivers=... \
                       --with-gallium-drivers=...

   The main library and OpenGL is enabled by default. The first two
   options above enables `OpenGL ES 1.x and 2.x <opengles.html>`__. The
   last two options enables the listed classic and and Gallium drivers
   respectively.

#. Build and install Mesa as usual.

In the given example, it will build and install ``libEGL``, ``libGL``,
``libGLESv1_CM``, ``libGLESv2``, and one or more EGL drivers.

.. rubric:: Configure Options
   :name: configure-options

There are several options that control the build of EGL at configuration
time

``--enable-egl``
    By default, EGL is enabled. When disabled, the main library and the
    drivers will not be built.

``--with-egl-driver-dir``
    The directory EGL drivers should be installed to. If not specified,
    EGL drivers will be installed to ``${libdir}/egl``.

``--with-egl-platforms``
    List the platforms (window systems) to support. Its argument is a
    comma separated string such as ``--with-egl-platforms=x11,drm``. It
    decides the platforms a driver may support. The first listed
    platform is also used by the main library to decide the native
    platform: the platform the EGL native types such as
    ``EGLNativeDisplayType`` or ``EGLNativeWindowType`` defined for.

    The available platforms are ``x11``, ``drm``, ``wayland``,
    ``surfaceless``, ``android``, and ``haiku``. The ``android``
    platform can either be built as a system component, part of AOSP,
    using ``Android.mk`` files, or cross-compiled using appropriate
    ``configure`` options. The ``haiku`` platform can only be built with
    SCons. Unless for special needs, the build system should select the
    right platforms automatically.

``--enable-gles1``
``--enable-gles2``
    These options enable OpenGL ES support in OpenGL. The result is one
    big internal library that supports multiple APIs.

``--enable-shared-glapi``
    By default, ``libGL`` has its own copy of ``libglapi``. This options
    makes ``libGL`` use the shared ``libglapi``. This is required if
    applications mix OpenGL and OpenGL ES.

.. rubric:: Use EGL
   :name: use-egl

.. rubric:: Demos
   :name: demos

There are demos for the client APIs supported by EGL. They can be found
in mesa/demos repository.

.. rubric:: Environment Variables
   :name: environment-variables

There are several environment variables that control the behavior of EGL
at runtime

``EGL_DRIVERS_PATH``
    By default, the main library will look for drivers in the directory
    where the drivers are installed to. This variable specifies a list
    of colon-separated directories where the main library will look for
    drivers, in addition to the default directory. This variable is
    ignored for setuid/setgid binaries.

    This variable is usually set to test an uninstalled build. For
    example, one may set

    ::

          $ export LD_LIBRARY_PATH=$mesa/lib
          $ export EGL_DRIVERS_PATH=$mesa/lib/egl

    to test a build without installation

``EGL_DRIVER``
    This variable specifies a full path to or the name of an EGL driver.
    It forces the specified EGL driver to be loaded. It comes in handy
    when one wants to test a specific driver. This variable is ignored
    for setuid/setgid binaries.

``EGL_PLATFORM``
    This variable specifies the native platform. The valid values are
    the same as those for ``--with-egl-platforms``. When the variable is
    not set, the main library uses the first platform listed in
    ``--with-egl-platforms`` as the native platform.

    Extensions like ``EGL_MESA_drm_display`` define new functions to
    create displays for non-native platforms. These extensions are
    usually used by applications that support non-native platforms.
    Setting this variable is probably required only for some of the
    demos found in mesa/demo repository.

``EGL_LOG_LEVEL``
    This changes the log level of the main library and the drivers. The
    valid values are: ``debug``, ``info``, ``warning``, and ``fatal``.

.. rubric:: EGL Drivers
   :name: egl-drivers

``egl_dri2``
This driver supports both ``x11`` and ``drm`` platforms. It functions as
a DRI driver loader. For ``x11`` support, it talks to the X server
directly using (XCB-)DRI2 protocol.

This driver can share DRI drivers with ``libGL``.

.. rubric:: Packaging
   :name: packaging

The ABI between the main library and its drivers are not stable. Nor is
there a plan to stabilize it at the moment.

.. rubric:: Developers
   :name: developers

The sources of the main library and drivers can be found at
``src/egl/``.

.. rubric:: Lifetime of Display Resources
   :name: lifetime-of-display-resources

Contexts and surfaces are examples of display resources. They might live
longer than the display that creates them.

In EGL, when a display is terminated through ``eglTerminate``, all
display resources should be destroyed. Similarly, when a thread is
released through ``eglReleaseThread``, all current display resources
should be released. Another way to destroy or release resources is
through functions such as ``eglDestroySurface`` or ``eglMakeCurrent``.

When a resource that is current to some thread is destroyed, the
resource should not be destroyed immediately. EGL requires the resource
to live until it is no longer current. A driver usually calls
``eglIs<Resource>Bound`` to check if a resource is bound (current) to
any thread in the destroy callbacks. If it is still bound, the resource
is not destroyed.

The main library will mark destroyed current resources as unlinked. In a
driver's ``MakeCurrent`` callback, ``eglIs<Resource>Linked`` can then be
called to check if a newly released resource is linked to a display. If
it is not, the last reference to the resource is removed and the driver
should destroy the resource. But it should be careful here because
``MakeCurrent`` might be called with an uninitialized display.

This is the only mechanism provided by the main library to help manage
the resources. The drivers are responsible to the correct behavior as
defined by EGL.

.. rubric:: ``EGL_RENDER_BUFFER``
   :name: egl_render_buffer

In EGL, the color buffer a context should try to render to is decided by
the binding surface. It should try to render to the front buffer if the
binding surface has ``EGL_RENDER_BUFFER`` set to ``EGL_SINGLE_BUFFER``;
If the same context is later bound to a surface with
``EGL_RENDER_BUFFER`` set to ``EGL_BACK_BUFFER``, the context should try
to render to the back buffer. However, the context is allowed to make
the final decision as to which color buffer it wants to or is able to
render to.

For pbuffer surfaces, the render buffer is always ``EGL_BACK_BUFFER``.
And for pixmap surfaces, the render buffer is always
``EGL_SINGLE_BUFFER``. Unlike window surfaces, EGL spec requires their
``EGL_RENDER_BUFFER`` values to be honored. As a result, a driver should
never set ``EGL_PIXMAP_BIT`` or ``EGL_PBUFFER_BIT`` bits of a config if
the contexts created with the config won't be able to honor the
``EGL_RENDER_BUFFER`` of pixmap or pbuffer surfaces.

It should also be noted that pixmap and pbuffer surfaces are assumed to
be single-buffered, in that ``eglSwapBuffers`` has no effect on them. It
is desirable that a driver allocates a private color buffer for each
pbuffer surface created. If the window system the driver supports has
native pbuffers, or if the native pixmaps have more than one color
buffers, the driver should carefully attach the native color buffers to
the EGL surfaces, re-route them if required.

There is no defined behavior as to, for example, how ``glDrawBuffer``
interacts with ``EGL_RENDER_BUFFER``. Right now, it is desired that the
draw buffer in a client API be fixed for pixmap and pbuffer surfaces.
Therefore, the driver is responsible to guarantee that the client API
renders to the specified render buffer for pixmap and pbuffer surfaces.

.. rubric:: ``EGLDisplay`` Mutex
   :name: egldisplay-mutex

The ``EGLDisplay`` will be locked before calling any of the dispatch
functions (well, except for GetProcAddress which does not take an
``EGLDisplay``). This guarantees that the same dispatch function will
not be called with the sample display at the same time. If a driver has
access to an ``EGLDisplay`` without going through the EGL APIs, the
driver should as well lock the display before using it.

.. raw:: html

   </div>