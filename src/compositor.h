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

#ifndef COMPOSITOR_H_
#define COMPOSITOR_H_

#include <iostream>
#include <memory>

#include "include/wlroots_full.h"

namespace server {

class Compositor {
public:
    Compositor();
    ~Compositor();

    void start();

private:
    // wayland
    wl_display *wl_display_;
    wl_event_loop *wl_event_loop_;

    // wlroots
    wlr_backend *wlr_backend_;
    wlr_session *wlr_session_;
    wlr_allocator *wlr_allocator_;
    wlr_renderer *wlr_renderer_;
    wlr_compositor *wlr_compositor_;

    int drm_fd_;

    const char *wl_display_socket_;
};

}

#endif
