/*
 * Copyright 2016 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef ST_PBO_H
#define ST_PBO_H

struct gl_pixelstore_attrib;

struct st_context;

struct st_pbo_addresses {
   int xoffset;
   int yoffset;
   unsigned width;
   unsigned height;
   unsigned depth;

   unsigned bytes_per_pixel;

   /* Everything below is filled in by st_pbo_from_pixelstore */
   unsigned pixels_per_row;
   unsigned image_height;

   /* Everything below is filled in by st_pbo_setup_buffer */

   /* Buffer and view. */
   struct pipe_resource *buffer; /* non-owning pointer */
   unsigned first_element;
   unsigned last_element;

   /* Constant buffer for the fragment shader. */
   struct {
      int32_t xoffset;
      int32_t yoffset;
      int32_t stride;
      int32_t image_size;
   } constants;
};

bool
st_pbo_addresses_setup(struct st_context *st,
                       struct pipe_resource *buf, intptr_t buf_offset,
                       struct st_pbo_addresses *addr);

bool
st_pbo_addresses_pixelstore(struct st_context *st,
                            GLenum gl_target, bool skip_images,
                            const struct gl_pixelstore_attrib *store,
                            const void *pixels,
                            struct st_pbo_addresses *addr);

bool
st_pbo_draw(struct st_context *st, const struct st_pbo_addresses *addr,
            unsigned surface_width, unsigned surface_height);

void *
st_pbo_create_vs(struct st_context *st);

void *
st_pbo_create_gs(struct st_context *st);

void *
st_pbo_create_upload_fs(struct st_context *st);

extern void
st_init_pbo_helpers(struct st_context *st);

extern void
st_destroy_pbo_helpers(struct st_context *st);

#endif /* ST_PBO_H */