/*
 * Copyright © 2022 Reion Wong (reionwong@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef WLROOTS_FULL_H_
#define WLROOTS_FULL_H_

extern "C" {
#include <wlr/backend.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_output_damage.h>
#include <wlr/util/region.h>
#include <wlr/types/wlr_screencopy_v1.h>

#define static
#include <wlr/types/wlr_compositor.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/render/allocator.h>
#include <wlr/render/gles2.h>
#include <wlr/render/egl.h>
#include <wlr/types/wlr_matrix.h>
#undef static

// Types
#define static
#include <wlr/types/wlr_scene.h>
#undef static

// Output management
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_output_management_v1.h>

// Input
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_xcursor_manager.h>
#include <wlr/xcursor.h>
#include <wlr/types/wlr_data_device.h>
}

#endif