/*
 * Copyright 2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdarg.h>
#include <openssl/bio.h>
#include <openssl/core.h>
#include "prov/provider_ctx.h"

int ossl_prov_bio_from_dispatch(const OSSL_DISPATCH *fns);

OSSL_CORE_BIO *ossl_prov_bio_new_file(const char *filename, const char *mode);
OSSL_CORE_BIO *ossl_prov_bio_new_membuf(const char *filename, int len);
int ossl_prov_bio_read_ex(OSSL_CORE_BIO *bio, void *data, size_t data_len,
                          size_t *bytes_read);
int ossl_prov_bio_write_ex(OSSL_CORE_BIO *bio, const void *data, size_t data_len,
                           size_t *written);
int ossl_prov_bio_free(OSSL_CORE_BIO *bio);
int ossl_prov_bio_vprintf(OSSL_CORE_BIO *bio, const char *format, va_list ap);
int ossl_prov_bio_printf(OSSL_CORE_BIO *bio, const char *format, ...);

BIO_METHOD *bio_prov_init_bio_method(void);
BIO *bio_new_from_core_bio(PROV_CTX *provctx, OSSL_CORE_BIO *corebio);
