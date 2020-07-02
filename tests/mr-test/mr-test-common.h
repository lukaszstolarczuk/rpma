/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright 2020, Intel Corporation
 */

/*
 * mr-test-common.h -- the memory region unit tests's common definitions
 */

#ifndef MR_COMMON_H
#define MR_COMMON_H

#include <stdlib.h>
#include <infiniband/verbs.h>

#include "cmocka_headers.h"
#include "mr.h"
#include "librpma.h"
#include "rpma_err.h"

extern struct ibv_mr Ibv_mr;

#define MOCK_PEER	(struct rpma_peer *)0x0AD0
#define MOCK_PTR	(void *)0x0001020304050607
#define MOCK_SIZE	(size_t)0x08090a0b0c0d0e0f
#define MOCK_RKEY	(uint32_t)0x10111213
#define MOCK_USAGE	(int)(RPMA_MR_USAGE_READ_SRC | RPMA_MR_USAGE_READ_DST)
#define MOCK_PLT	RPMA_MR_PLT_PERSISTENT
#define MOCK_MR		(struct ibv_mr *)&Ibv_mr
#define MOCK_ERRNO	(int)(123)
#define MOCK_OK		(int)0

#define DESC_EXP	{0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, \
			0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08, \
			0x13, 0x12, 0x11, 0x10, \
			0x01}

/* prestate structure passed to unit test functions */
struct prestate {
	int usage;
	int access;
	/* mr passed from setup to test and to teardown */
	struct rpma_mr_local *mr;
};

/* structure of arguments used in rpma_peer_mr_reg() */
struct rpma_peer_mr_reg_args {
	int usage;
	int access;
	struct ibv_mr *mr;
	int verrno;
};

/* setups & teardowns */

int setup__reg_success(void **pprestate);

int teardown__dereg_success(void **pprestate);

#endif /* MR_COMMON_H */
