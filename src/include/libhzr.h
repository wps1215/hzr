#ifndef LIBHZR_H_
#define LIBHZR_H_

#include <stddef.h> /* For size_t */

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Return value for many libhzr functions.
*/
typedef enum {
  HZR_FAIL = 0, /**< Failure (zero). */
  HZR_OK = 1    /**< Success (non-zero). */
} hzr_status_t;

/**
* @brief Determine the maximum (worst case) size of an HZR encoded buffer.
* @param uncompressed_size Size of the uncompressed buffer in bytes.
* @returns The maximum size (in bytes) of the compressed buffer.
*/
size_t hzr_max_compressed_size(size_t uncompressed_size);

/**
* @brief Compress a buffer using the HZR compression scheme.
* @param in Input (uncompressed) buffer.
* @param in_size Size of the input buffer in bytes.
* @param[out] out Output (compressed) buffer.
* @param[out] out_size Size of the output buffer in bytes.
* @returns HZR_OK on success, else HZR_FAIL.
*/
hzr_status_t hzr_encode(const void* in,
                        size_t in_size,
                        void* out,
                        size_t out_size);

/**
* @brief Decode an HZR encoded buffer.
* @param in Input (compressed) buffer.
* @param in_size Size of the input buffer in bytes.
* @param[out] out Output (uncompressed) buffer.
* @param[out] out_size Size of the output buffer in bytes.
* @returns HZR_OK on success, else HZR_FAIL.
*/
hzr_status_t hzr_decode(const void* in,
                        size_t in_size,
                        void* out,
                        size_t out_size);

#ifdef __cplusplus
}
#endif

#endif /* LIBHZR_H_ */