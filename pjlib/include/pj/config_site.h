/*
 * Softphone Framework build configuration.
 *
 * Common settings live here. Capacity limits depend on the ioqueue backend
 * chosen by ./configure (PJ_IOQUEUE_IMP, from <pj/compat/os_auto.h>, which
 * is included before this file):
 *   - epoll  (./configure --enable-epoll) : config_site_epoll.h
 *   - others (select, kqueue)             : config_site_select.h
 *
 * The select ioqueue requires PJ_IOQUEUE_MAX_HANDLES <= FD_SETSIZE.
 */

/* The PJ_IOQUEUE_IMP_xxx constants are only defined later in <pj/config.h>,
 * so define the ones compared below. Values must match <pj/config.h>; a
 * mismatch produces a macro redefinition diagnostic.
 */
#ifndef PJ_IOQUEUE_IMP_SELECT
#   define PJ_IOQUEUE_IMP_SELECT        1
#endif
#ifndef PJ_IOQUEUE_IMP_EPOLL
#   define PJ_IOQUEUE_IMP_EPOLL         2
#endif

#if defined(PJ_IOQUEUE_IMP) && PJ_IOQUEUE_IMP == PJ_IOQUEUE_IMP_EPOLL
#   include <pj/config_site_epoll.h>
#else
#   include <pj/config_site_select.h>
#endif

#define PJSUA_MAX_CONF_PORTS            (PJSUA_MAX_CALLS+2*PJSUA_MAX_PLAYERS)

#define PJ_SCANNER_USE_BITWISE          0
#undef PJ_OS_HAS_CHECK_STACK
#define PJ_OS_HAS_CHECK_STACK           0
#define PJ_LOG_MAX_LEVEL                5
#define PJSIP_MAX_TSX_COUNT             ((640*1024)-1)
#define PJSIP_MAX_DIALOG_COUNT          ((640*1024)-1)
#define PJSIP_UDP_SO_SNDBUF_SIZE        (24*1024*1024)
#define PJSIP_UDP_SO_RCVBUF_SIZE        (24*1024*1024)
#define PJ_DEBUG                        0
#define PJSIP_SAFE_MODULE               0
#define PJ_HAS_STRICMP_ALNUM            0
#define PJSIP_UNESCAPE_IN_PLACE         1

// disable media codecs
#define PJMEDIA_HAS_SPEEX_CODEC         0
#define PJMEDIA_HAS_ILBC_CODEC          0
#define PJMEDIA_HAS_GSM_CODEC           0
#define PJMEDIA_HAS_L16_CODEC           0
#define PJMEDIA_HAS_OPENCORE_AMRNB_CODEC 0

// OPUS
#define PJMEDIA_CODEC_OPUS_DEFAULT_COMPLEXITY   1
#define PJMEDIA_CODEC_OPUS_DEFAULT_SAMPLE_RATE  16000

// Transport
#define PJSIP_TRANSPORT_IDLE_TIME       600
/* TLS 1.0 and 1.1 are deprecated (RFC 8996) */
#define PJSIP_SSL_DEFAULT_PROTO         (PJ_SSL_SOCK_PROTO_TLS1_2 | \
                                         PJ_SSL_SOCK_PROTO_TLS1_3)
