/*
 * Softphone Framework capacity limits for the epoll ioqueue
 * (./configure --enable-epoll). Included from config_site.h.
 */
#define PJSUA_MAX_PLAYERS               8192
#define PJSUA_MAX_RECORDERS             8192
#define PJSUA_MAX_CALLS                 8192
#define PJSUA_MAX_ACC                   8192
#define PJ_IOQUEUE_MAX_HANDLES          (PJSUA_MAX_CALLS*2)
