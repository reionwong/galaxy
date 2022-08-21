set(MAIN_SRCS
  main.cpp
  compositor.cpp
  events.cpp
  utils/command_line_helper.cpp
)

add_executable(galaxy ${MAIN_SRCS})

add_wayland_server_protocol(galaxy PROTOCOL ${WaylandProtocols_DATADIR}/stable/xdg-shell/xdg-shell.xml BASENAME xdg-shell)

target_link_libraries(galaxy
  PUBLIC
    Wayland::Server
    Wayland::Cursor

    wlroots::wlroots

    ${PIXMAN_LIBRARY}
)