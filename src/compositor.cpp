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