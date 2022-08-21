#ifndef COMPOSITOR_H_
#define COMPOSITOR_H_

#include <iostream>
#include <memory>

extern "C" {
#include <wlr/backend.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_input_device.h>
#define static
#include <wlr/render/allocator.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/render/wlr_renderer.h>
#undef static
}

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
