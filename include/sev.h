// SPDX-License-Identifier: Apache-2.0
/*
 * AMD SEV, SEV-SNP library
 *
 * See sev(3) for API documentation.
 */

#ifndef SEV_H
#define SEV_H

#ifdef __cplusplus
extern "C" {
#endif

int sev_init(int, int, int *);
int sev_es_init(int, int, int *);
int sev_launch_start(int, uint32_t, const void *, const void *, int *);
int sev_launch_update_data(int, uint64_t, uint64_t, int *);
int sev_launch_update_vmsa(int, int *);
int sev_launch_measure(int, unsigned char *, int *);
int sev_inject_launch_secret(int,
                             const unsigned char *,
                             const unsigned char *,
                             uint32_t,
                             const void *,
                             int *);
int sev_launch_finish(int, int *);

#ifdef __cplusplus
}
#endif

#endif /* SEV_H */
