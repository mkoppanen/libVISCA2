#include "libvisca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifdef VISCA_WIN
#include <winsock.h>
#else
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

typedef struct _VISCA_tcp_ctx {
	int sockfd;
} VISCA_tcp_ctx_t;

static int visca_tcp_cb_write(VISCAInterface_t *iface, const void *buf, int length)
{
	VISCA_tcp_ctx_t *ctx = iface->ctx;
	return send(ctx->sockfd, buf, length, 0);
}

static int visca_tcp_cb_read(VISCAInterface_t *iface, void *buf, int length)
{
	VISCA_tcp_ctx_t *ctx = iface->ctx;
	return recv(ctx->sockfd, buf, length, 0);
}

static int visca_tcp_cb_close(VISCAInterface_t *iface)
{
	if (!iface || !iface->ctx)
		return VISCA_FAILURE;
	VISCA_tcp_ctx_t *ctx = iface->ctx;

	// read the rest of the data: (should be empty)
	unsigned char packet[3000];
	uint32_t buffer_size = 3000;

	if (ctx->sockfd != -1) {
		close(ctx->sockfd);
		free(ctx);
		iface->ctx = NULL;
		return VISCA_SUCCESS;
	} else
		return VISCA_FAILURE;
}

static VISCA_callback_t visca_tcp_cb = {
	.write = visca_tcp_cb_write,
	.read = visca_tcp_cb_read,
	.close = visca_tcp_cb_close,
};

static int initialize_socket(VISCA_tcp_ctx_t *ctx, const char *hostname, int port)
{
	struct hostent *servhost = gethostbyname(hostname);
	if (!servhost) {
		u_long addr = inet_addr(hostname);
		servhost = gethostbyaddr((char *)&addr, sizeof(addr), AF_INET);
		if (!servhost) {
			fprintf(stderr, "Error: cannot get server address for \"%s\"\n", hostname);
			return 1;
		}
	}

	ctx->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (ctx->sockfd < 0) {
		fprintf(stderr, "Error: cannot create socket\n");
		return 1;
	}

	struct sockaddr_in server = {
		.sin_family = AF_INET,
		.sin_port = htons(port),
	};
	memcpy(&server.sin_addr, servhost->h_addr, servhost->h_length);
	if (connect(ctx->sockfd, (struct sockaddr *)&server, sizeof(server))) {
		fprintf(stderr, "Error: cannot connect to host \"%s\" port %d\n", hostname, port);
		close(ctx->sockfd);
		ctx->sockfd = -1;
		return 1;
	}

	return 0;
}

uint32_t VISCA_open_tcp(VISCAInterface_t *iface, const char *hostname, int port)
{
	VISCA_tcp_ctx_t *ctx = calloc(1, sizeof(VISCA_tcp_ctx_t));

	if (initialize_socket(ctx, hostname, port)) {
		free(ctx);
		return VISCA_FAILURE;
	}

	iface->callback = &visca_tcp_cb;
	iface->ctx = ctx;
	iface->address = 0;
	iface->broadcast = 0;

	return VISCA_SUCCESS;
}
