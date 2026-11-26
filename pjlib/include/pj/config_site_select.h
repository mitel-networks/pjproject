/*
 * Softphone Framework capacity limits for the select ioqueue (and other
 * non-epoll backends). Included from config_site.h.
 *
 * PJ_IOQUEUE_MAX_HANDLES must not exceed FD_SETSIZE (1024 on Linux/macOS).
 */
#define PJSUA_MAX_PLAYERS               1024
#define PJSUA_MAX_RECORDERS             1024
#define PJSUA_MAX_CALLS                 1024
#define PJSUA_MAX_ACC                   4096
#define PJ_IOQUEUE_MAX_HANDLES          (PJSUA_MAX_CALLS*1)
