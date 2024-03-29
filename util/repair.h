#ifndef _REPAIR_H
#define _REPAIR_H

#include "gmime-extra.h"

#ifdef __cplusplus
extern "C" {
#endif

/* This is a collection of message structure and message format repair
 * techniques that are designed to improve the user experience of
 * notmuch */

/* If payload is a cryptographic payload within an encrypted message, and
 * it has a "legacy display" part, then we can skip over it and jump
 * to the actual content, because notmuch already handles protected
 * headers appropriately.
 *
 * This function either returns payload directly (if it does not have
 * a "legacy display" part), or it returns a pointer to its
 * content-bearing subpart, with the "legacy display" part and the
 * surrounding multipart/mixed object bypassed.
 *
 * No new objects are created by calling this function, and the
 * returned object will only be released when the original part is
 * disposed of.
 */
GMimeObject *
_notmuch_repair_crypto_payload_skip_legacy_display (GMimeObject *payload);

#ifdef __cplusplus
}
#endif
#endif
