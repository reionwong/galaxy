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

#include "compositor.h"

namespace server {

Compositor::Compositor()
{
    wl_display_ = wl_display_create();
    wl_event_loop_ = wl_display_get_event_loop(wl_display_);

    wlr_backend_ = wlr_backend_autocreate(wl_display_);
    if (!wlr_backend_) {
        throw std::runtime_error("wlr_backend_autocreate() failed.");
    }

    drm_fd_ = wlr_backend_get_drm_fd(wlr_backend_);
    if (drm_fd_ < 0) {
        std::cout << "Couldn't query the drm fd!";
        throw std::runtime_error("wlr_backend_get_drm_fd() failed.");
    }

    wlr_renderer_ = wlr_gles2_renderer_create_with_drm_fd(drm_fd_);
    if (!wlr_renderer_) {
        throw std::runtime_error("wlr_gles2_renderer_create_with_drm_fd() failed.");
    }
    wlr_renderer_init_wl_display(wlr_renderer_, wl_display_);

    wlr_allocator_ = wlr_allocator_autocreate(wlr_backend_, wlr_renderer_);

    wlr_compositor_ = wlr_compositor_create(wl_display_, wlr_renderer_);
}

Compositor::~Compositor()
{

}

void Compositor::start()
{
    wl_display_socket_ = wl_display_add_socket_auto(wl_display_);

    if (!wl_display_socket_) {
        wlr_backend_destroy(wlr_backend_);
        throw std::runtime_error("wl_display_add_socket_auto failed.");
    }

    std::cout << "WAYLAND_DISPLAY=" << wl_display_socket_ << std::endl;
    setenv("WAYLAND_DISPLAY", wl_display_socket_, 1);

    wl_display_run(wl_display_);
}

}